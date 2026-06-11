#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N,K;
  cin>>N>>K;
  ll sum = 0;
  vector<int> h(N);
  for(int i=0; i<N; i++){
    cin>>h.at(i);
  }
  sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
  if(K>=N) cout<<0<<endl;
  else{
  	for(int i=K; i<N; i++){
    	sum+=h.at(i);
    }
    cout<<sum<<endl;
  }
}