#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int m=0;
  int sum=0;
  int G[13]={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161};
  for(int i=12;i>=0;i--){
    if(N/G[i]>=1){
      m=i;
      break;
    }
  }
  cout << m+1 << endl;
  for(int i=m;i>=0;i--){
    for(int j=G[i];j<=N-1;j++){
    int v=A[j];
    int k=j-G[i];
 while(k>=0 && A[k]>v){
    A[k+G[i]]=A[k];
    k=k-G[i];
    sum++;
    A[k+G[i]]=v;
  }
  }
  if(i>0){
    cout << G[i] << " ";
  }
  else if(i==0){
    cout << G[i] << endl << sum << endl;
  }
 }
 for(int i=0;i<N;i++){
    cout << A[i] << endl;
  }
}  
