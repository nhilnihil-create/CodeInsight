#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,A,count=0;
  cin>>N>>K;
  vector<int> m(K);
  vector<int> n(N);
  
  for(int i=0; i<K; i++){
    cin>>m.at(i);
    for(int j=0; j<m.at(i); j++){
      cin>>A;
      n.at(A-1)++;
    }
  }
  for(int i=0; i<N; i++){
    if(n.at(i)==0){
      count++;
    }
  }
  cout<<count<<endl;
}