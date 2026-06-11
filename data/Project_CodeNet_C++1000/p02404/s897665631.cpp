#include<stdio.h>

int n,m;

void proc(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      printf("%c",(i==0||i==n-1||(j==0||j==m-1))?'#':'.');
    printf("\n");
  }
  printf("\n");
}

int main(){
  while(true){
    scanf("%d%d", &n, &m);
    if(!n&&!m)return 0;
    proc();
  }
}