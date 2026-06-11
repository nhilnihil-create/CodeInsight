#include<bits/stdc++.h>
using namespace std;

#define N 1000000
#define M 100

long int cnt;
int A[N];

void insertionSort(int n, int g){
  int i, j;
  int v;
  
  for(i=g; i<n; i++){
    v=A[i];
    for(j=i-g; 0<=j && A[j]>v; j-=g){
      A[j+g]=A[j];
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int n){
  int G[M], g_num;

  for(int i=1, j=0; ;j++){
    G[j]=i;
    i=3*i+1;
    if(i>n){
      g_num=j+1;
      break;
    }
  }

  for(int i=0; i<g_num/2; i++) swap(G[i], G[g_num-1-i]);
  
  printf("%d\n", g_num);
  for(int i=0; i<g_num; i++){
    if(i) printf(" %d",G[i]);
    else  printf("%d", G[i]);
  }
  printf("\n");
  
  for(int i=0; i<g_num; i++){
    insertionSort(n, G[i]);
  }
}

int main(void){

  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%d", A+i);  
  shellSort(n);

  printf("%d\n", cnt);
  for(int i=0; i<n; i++) printf("%d\n",A[i]);
  
  return 0;
}

