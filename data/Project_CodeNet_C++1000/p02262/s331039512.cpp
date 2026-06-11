#include <bits/stdc++.h>
#define N 1000010
using namespace std;
int cnt=0;
void insertionSort(int *A,int n,int g){
  for(int i=g;i<n;i++){
    int v = A[i];
    int j = i - g;
    while(j>=0 && A[j]>v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}



void shellSort(int *A,int n){
  cnt = 0 ;
  int m = 1;//
  int G[25] = {1};
  for(int i=1;G[i-1]*2<=n;i++)G[i] = G[i-1]*2,m++;
  for(int i=0;i<m;i++) insertionSort(A,n,G[m-1-i]);
  
  cout<<m<<endl;
  for(int i=0;i<m;i++){
    if(i)printf(" ");
    printf("%d",G[m-1-i]);
  }
  cout<<endl;
}

int main(){
  int n,A[N];
  cin>>n;
  for(int i=0;i<n;i++)scanf("%d",&A[i]);
  
  shellSort(A,n);
  
  cout<<cnt<<endl;
  for(int i=0;i<n;i++) printf("%d\n",A[i]);
  
  return 0;
}