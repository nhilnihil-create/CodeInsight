#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll ans=0;
  string ABC="ABC";
  for(ll i=0;i<N-2;i++){
    string T="";
    for(ll j=i;j<i+3;j++){
      T+=S[j];
    }
    if(T==ABC){
      ans++;
    }
  }
  cout << ans <<  endl;
}