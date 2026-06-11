#include<cstdio>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define MAX_V 250
int heap[MAX_V]{0};

int main(){
  int n; scanf("%d",&n);
  REP(i,n) scanf("%d",&heap[i]);
  REP(i,n){
    printf("node %d: key = %d, ",i+1,heap[i]);
    if(i>0) printf("parent key = %d, ",heap[(i-1)/2]);
    if(n>2*i+1) printf("left key = %d, ",heap[2*i+1]);
    if(n>2*i+2) printf("right key = %d, ",heap[2*i+2]);
    puts("");
  }
}