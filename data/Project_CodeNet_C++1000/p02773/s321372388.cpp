#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,max=0;
  cin >> N;
  string S;
  map<string, ll> vote; 
  rep(i,N){
    cin >> S;
    vote[S]++;
    if(vote[S]>max) max=vote[S];
  }
  int n=vote.size();
  rep(i,n){
    //cout << vote[i] << endl;
  }
  for (auto p : vote) {
  auto k = p.first;
  auto v = p.second;
  if(v==max) cout << k << endl;
}
  return 0;
}
