#include<stdio.h>
#include<stdlib.h>

int cnt=0;
int n;
void insertionSort(int *A,int g){
  int i,j;
  int v;
  for(i=g;i<n;i++){
    v = A[i];
    j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

int main(){
  int i;
  int m=0;
  int *A;
  int *G;
  int nn=1;
  scanf("%d",&n);
  while(nn<=n){
      m++;
      nn*=2;
  }
  A = (int *)calloc(n,sizeof(int));
  G = (int *)calloc(m,sizeof(int));
  G[m-1]=1;
  for(i=m-2;i>=0;i--){
    G[i]=2*G[i+1];
  }
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<m;i++){
    insertionSort(A,G[i]);
  }
  printf("%d\n",m);
  for(i=0;i<m-1;i++){
    printf("%d ",G[i]);
  }
  printf("%d\n%d\n",G[m-1],cnt);
  for(i=0;i<n;i++){
    printf("%d\n",A[i]);
  }
}