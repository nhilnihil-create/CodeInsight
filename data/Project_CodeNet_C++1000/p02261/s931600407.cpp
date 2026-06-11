#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Card{
  char suit;
  char value;
};

void BubbleSort(Card C[], int N);
void SelectionSort(Card C[], int N);
void trace(Card C[], int N);
int judge(Card C1[], Card C2[], int N);

int main()
{
  int N;
  int i;
  char c[3];
  struct Card C1[36], C2[36];

  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%s", c);
    C1[i].suit = c[0];
    C1[i].value = c[1];
  }

  for(i = 0; i < N; i++){
    C2[i] = C1[i];
  }
  BubbleSort(C1, N);
  trace(C1, N);
  printf("Stable\n");

  SelectionSort(C2, N);
  trace(C2, N);
  if(judge(C1, C2, N)){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}


void BubbleSort(Card C[], int N){
  int i, j;

  for(i = 0; i < N; i++){
    for(j = N-1; j > i; j--){
      if(C[j].value < C[j-1].value){
        Card t;
        t = C[j];
        C[j] = C[j-1];
        C[j-1] = t;
      }
    }
  }
}

void SelectionSort(Card C[], int N){
  int i, j, minj;

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(C[j].value < C[minj].value) minj = j;
    }
    Card t;
    t = C[i];
    C[i] = C[minj];
    C[minj] = t;
  }
}

void trace(Card C[], int N){
  int i;
  for(i = 0; i < N; i++){
    printf("%c%c",C[i].suit, C[i].value);
    if(i == N-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
}

int judge(Card C1[], Card C2[], int N){
  int i;
  for(i = 0; i < N; i++){
    if(C1[i].suit != C2[i].suit)
      return 0;
  }
  return 1;
}

