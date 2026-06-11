#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >> N;
  ll ans=0;
  for(ll i=1;i<=N;i++){
    for(ll j=1;j*i<=N;j++){
        ans+=j*i;
    }
  }
  cout << ans <<endl;
}