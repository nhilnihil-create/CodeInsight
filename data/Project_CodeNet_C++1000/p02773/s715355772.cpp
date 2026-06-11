#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  map<string,ll> vote;
  for(ll i=0;i<N;i++){
    string S;
    cin >> S;
    vote[S]++;
  }
  ll max=0;
  for(auto j=vote.begin(); j!=vote.end();++j){
    if(j->second > max){
      max=j->second;
    }
  }
  for(auto j=vote.begin(); j!=vote.end();++j){
    if(j->second ==max){
      cout << j->first << endl;
    }
  }
}