#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long cnt;
int l,n;
int A[1000000];
vector<int> G;


void insertion(int A[], int n,int g){
  int i,V,j;
  for ( i = g; i < n; i++ ){
  V=A[i];
  j=i-g;
  while (j>=0 && A[j]>V){
	  A[j+g]=A[j];
      j -= g;
      cnt++;
  }
  A[j+g]=V;
  }
}

void shellsort(int A[], int n){
  for(int h=1;;){
  if(h>n) break;
  G.push_back(h);
  h=3*h+1;
  }
  for(int i= G.size()-1;i>=0;i--){
  insertion(A,n,G[i]);
  }
}

int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++ ) scanf("%d", &A[i]);
  cnt=0;
  shellsort(A,n);
  cout << G.size() << endl;
  for(int i= G.size()-1;i>=0;i--){
    printf("%d", G[i]);
    if ( i ) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for(int i=0;i<n;i++) printf("%d\n",A[i]);
  return 0;
}