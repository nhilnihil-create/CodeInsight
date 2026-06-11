#include<stdio.h>
#include <string.h>
#include<stdlib.h>

struct Card{
  char suit;
  char value;
};

typedef struct {
  char value;
  char suit[4]; // suit order
} same_t;

void swap(struct Card*, struct Card*);
void pr(struct Card*, int);
int a2n(char);
void chkSt( struct Card*, struct Card*, int);

int main(){
  struct Card C1[101], C2[101];
  int n, i, j;
  int mini;
  char ch; // spacer

  scanf("%d%c", &n, &ch);

  for ( i = 0; i <= n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }

  // bubble sort
  memcpy( C2, C1, sizeof(C1));
  for( i = 0 ; i < n ; i++){
    for(j = n-1 ; j > i ; j--){
      if( a2n(C2[j].value) < a2n(C2[j-1].value) ){
	swap(&C2[j] ,&C2[j-1]);
      }
    }
  }
  pr(C2,n);
  chkSt(C1,C2,n);

  // slection sort
  memcpy( C2, C1, sizeof(C1));
  for( i = 0 ; i < n ; i++){
    mini = i;
    for(j = i ; j < n ; j++){
      if( a2n(C2[j].value) < a2n(C2[mini].value) ){
	mini = j;
      }
    }
    if( i != mini){
      swap(&C2[i] ,&C2[mini]);
    }
  }
  pr(C2,n);  
  chkSt(C1,C2,n);

  return 0;
}

void chkSt( struct Card* c1_p, struct Card* c2_p, int n){
  same_t chk[101]={0}; // 0 is teminater
  int i, j, k;

  j = -1;
  for(i=0 ; i<n ; i++){
    k = 0;
    if(a2n(c2_p[i].value)==a2n(c2_p[i+1].value)){
      j++;
      chk[j].value   = c2_p[i].value;
      chk[j].suit[0] = c2_p[i].suit;
      chk[j].suit[1] = c2_p[i+1].suit;
      k++;
    }
    if(a2n(c2_p[i].value)==a2n(c2_p[i+2].value)){
      chk[j].suit[2] = c2_p[i+2].suit;
      k++;
    }
    if(a2n(c2_p[i].value)==a2n(c2_p[i+3].value)){
      chk[j].suit[3] = c2_p[i+3].suit;
      k++;
    }
    i += k;
  }  

  for(i=0 ; chk[i].value != 0 ; i++){
    k =0;
    for(j=0 ; j < n ; j++){
      if(chk[i].value == c1_p[j].value ){
	if( chk[i].suit[k] == c1_p[j].suit){
	  k++;
	  if( k==4){
	    break;
	  }
	}else{
	  printf("Not stable\n");
	  return;
	}
      }
    }
  }
 
  printf("Stable\n");
  return;
}

int a2n(char a){
  return a - '0';
}

void swap(struct Card *a_p, struct Card *b_p){
  struct Card k;
  memcpy( &k,  a_p, sizeof(*a_p));
  memcpy( a_p, b_p, sizeof(*a_p));
  memcpy( b_p, &k, sizeof(*a_p));
}

void pr(struct Card *a_p, int n){
  int i;
  for( i = 0 ; i < n ; i++ ){
    printf("%c%c" ,a_p[i].suit ,a_p[i].value );
    if( i != (n-1)){
      printf(" ");
    }
  }
  printf("\n");
}