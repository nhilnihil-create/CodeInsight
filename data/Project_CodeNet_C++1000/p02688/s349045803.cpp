#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,K;
  cin>>N>>K;
  
  vector<int> d;
  vector<vector<int>> A;
  
  d.resize(K);
  A.resize(K,vector<int>());
  for(int i=0;i<K;i++){
    cin>>d[i];
    A[i].resize(d[i]);
    for(int j=0;j<d[i];j++){
      cin>>A[i][j];
    }
  }
  
  vector<int> check(N);
  for(int i=0;i<N;i++){
    check[i]=i+1;
  }
  
  for(int i=0;i<K;i++){
    for(int j=0;j<d[i];j++){
      for(int k=0;k<N;k++){
        if(A[i][j]==check[k]){
          check[k]=1000;
        }
      }
    }
  }
  
  int ans=0;
  
  for(int k=0;k<N;k++){
    if(check[k]==1000){
      ans++;
    }
  }
  
  cout<<N-ans<<endl;
}