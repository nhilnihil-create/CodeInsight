#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  long long sum=0;
  cin>>N>>K;
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin>>H.at(i);
  }
  sort(H.begin(),H.end());
  for(int i=0; i<N-K; i++){
    sum+=H.at(i);
  }
  cout<<sum<<endl;
}