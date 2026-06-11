#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N,M;
  cin >> N >> M;
  vector<ll> S(M);
  vector<ll> C(M);
  for(ll i=0;i<M;i++){
    cin >> S.at(i) >> C.at(i);
  }
  vector<ll> Number(N,-1);
  for(ll i=0;i<M;i++){
    for(ll j=0;j<i;j++){
      if(S.at(j)==S.at(i) && C.at(j)!=C.at(i)){
        cout << -1 << endl;
        return 0;
      }
    }
    Number.at(S.at(i)-1)=C.at(i);
  }
  if(Number.at(0)==0 && N!=1){
    cout << -1 << endl;
    return 0;
  }
  else if(Number.at(0)==-1 && N!=1){
    Number.at(0)=1;
  }
  else if(Number.at(0)==-1 && N==1){
    Number.at(0)=0;
  }
  for(ll i=0;i<N;i++){
    if(Number.at(i)==-1){
      Number.at(i)=0;
    }
    cout << Number.at(i);
  }
}
