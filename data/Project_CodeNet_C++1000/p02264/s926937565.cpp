#include <stdio.h>
#include <string.h>

typedef struct {
  char name[10];
  int t;
} P;


void enqueue(P);
P dequeue(void);

P Q[100000];
int head = 0;
int tail = 0;
int n,q,i,c=0,t=0,s;
P _Q;


int main(){

  scanf("%d %d",&n,&q);
  for(i=0;i<n;i++){
    scanf("%s%d",Q[i].name,&Q[i].t);
  }

  while(c!=n){
    _Q=dequeue();
    if(_Q.t<=q){
      t += _Q.t;
      c++;
      printf("%s %d\n",_Q.name,t);
    }else{
      t+=q;
      _Q.t-=q;
      enqueue(_Q);
    }
  }
  return 0;
}

void enqueue(P x){
  if(tail == n){
    tail = 0;
  }
  Q[tail++]=x;
}

P dequeue(void){
  if(head == n){
    head = 0;
  }
  return Q[head++];
}