#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,X;
  cin>>N>>X;
  
  vector<int> L(N);
  for(int i=0;i<N;i++){
    cin>>L[i];
  }
  
  
  vector<int> D(N);
  D[0]=0;
  for(int i=1;i<=N;i++){
    D[i]=D[i-1]+L[i-1];
  }
  
  int check=0;
  
  for(int i=0;i<=N;i++){
    if(D[i]<=X){
      check++;
    }
  }
  
  
  cout<<check<<endl;
}