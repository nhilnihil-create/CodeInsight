#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int n, A[1000010], cnt = 0;

void insertionSort(int A[],int n, int g){
  for(int i=g;i<n;i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v; 
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
  int m, G[1000000], i;
  G[0]=1;
  i = 0;
  if(n==1) m = 1;
  else{
    while(G[i]<n){
      G[i+1] = 3 * G[i] + 1;
      i++;
    }
    m = i;
  }
  cout<<m<<endl;
  for(int i=m-1;i>=0;i--){
    insertionSort(A, n, G[i]);
    cout<<G[i];
    if(i) cout<<" ";
  }
  cout<<endl;
  cout<<cnt<<endl;
  for(int i=0;i<n;i++) cout<<A[i]<<endl;
  return 0;
}

