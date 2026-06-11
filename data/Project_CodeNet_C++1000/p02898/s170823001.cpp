#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,count=0;
  cin>>N>>K;
  vector<int> h(N);
  for(int i=0; i<N; i++){
    cin>>h.at(i);
    if(K<=h.at(i)){
      count++;
    }
  }
  cout<<count<<endl;
}