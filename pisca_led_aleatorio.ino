#define LED_AMARELO 5
#define LED_AZUL 4
#define LED_VERDE 3
#define LED_VERMELHO 2

#define BOTAO_AMARELO 11
#define BOTAO_AZUL 10
#define BOTAO_VERDE 9
#define BOTAO_VERMELHO 8
#define TAMANHO_SEQUENCIA 4
#define INDEFINIDO -1

int sequenciaLuzes[TAMANHO_SEQUENCIA];

int inicialuzes[]={2,3,4,5};

int piscaled(int portaLed){
  digitalWrite(portaLed, HIGH);
  delay(1000); // Wait for 1000 
  digitalWrite(portaLed, LOW);
  delay(500); // Wait for 500
  return -1;
}
void iniciaJogo(){
  for(int indice = 0; indice < TAMANHO_SEQUENCIA; indice++){
    sequenciaLuzes[indice]=sorteaCor();
  }
}

void pisca4VezesAleatorias(){
  for(int indice = 0; indice < sizeof(sequenciaLuzes); indice++){
    piscaled(sequenciaLuzes[indice]);
  }
}
int sorteaCor(){
  return random (LED_VERMELHO, LED_AMARELO +1);
}
void sequencia2(){
  digitalWrite(LED_VERMELHO,HIGH);
  digitalWrite(LED_VERDE,HIGH);
  digitalWrite(LED_AZUL,HIGH);
  digitalWrite(LED_AMARELO,HIGH);
  delay(1000);
  digitalWrite(LED_VERMELHO,LOW);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AZUL,LOW);
  digitalWrite(LED_AMARELO,LOW);
  delay(500);
}
void sequencia1(){
  piscaled(5);
  piscaled(4);
  piscaled(3);
  piscaled(2);
}
void setup(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
    
}
int checaRespostaJogador(){
  if (digitalRead(BOTAO_VERMELHO)==LOW){
    return piscaled(2);
  }
  if (digitalRead(BOTAO_VERDE)==LOW){
    return piscaled(3);
  }
  if (digitalRead(BOTAO_AZUL)==LOW){
    return piscaled(4);
  }
  if (digitalRead(BOTAO_AMARELO)==LOW){
    return piscaled(5);
  }
  return INDEFINIDO;
}
void loop(){
  piscaled(sorteaCor());
  //iniciajogo();
  //
  // put your main code here, to run repeatedly:
  //sequencia1();
  //sequencia2();  
  //Serial.println (checaRespostaJogador());
 // int botaoApertado = checaRespostaJogador();
 // int estadoVermelho = digitalRead (BOTAO_VERMELHO);
 // Serial.println(estadoVermelho);
 // int estadoAmarelo = digitalRead (BOTAO_AMARELO);
 // Serial.println(estadoAmarelo);
}



