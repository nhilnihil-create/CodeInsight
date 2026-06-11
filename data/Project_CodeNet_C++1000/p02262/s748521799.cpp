#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <climits>

using namespace std;

int cnt;

void insertionSort(int *A,int n,int g){
  int v;
  for(int i=g;i<n;i++){
    v=A[i];
    int j = i - g;
    while (j>=0 && A[j] > v) {
      A[j+g] = A[j];
      j = j -g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int *A,int n){
  cnt = 0;
  int *G,g,m;


  for(m=1;m<=100;m++){
    g=((pow(3,m)-1)/2);
    if(g>n)
      break;
  }
  m--;
  printf("%d\n",m);

  G = (int *)malloc(m*sizeof(int));
  for(int i=m,c=0;i>0;i--,c++){
    G[c] = (pow(3,i)-1)/2;
  }

  for(int i=0;i<m;i++){
    printf("%d",G[i]);
    if(i<m-1)
      putchar(' ');
    else
      putchar('\n');
    insertionSort(A,n,G[i]);
  }
  printf("%d\n",cnt);
}

int main(){
  int n,*A;

  scanf("%d\n",&n);
  A = (int *)malloc(n*sizeof(int));

  for(int i=0;i<n;i++){
    scanf("%d\n",&A[i]);
  }

  shellSort(A,n);

  for(int i=0;i<n;i++){
    printf("%d\n",A[i]);
  }

}

