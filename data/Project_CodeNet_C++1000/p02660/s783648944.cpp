#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll,ll> sosuu;

void bunkai(ll &N){
  if(N%2==0){
    sosuu[2]++;
    N=N/2;
    return ;
  }
  for(ll i=3;i<=sqrt(N);i+=2){
    if(N%i==0){
      sosuu[i]++;
      N=N/i;
      return ;
    }
  }
  sosuu[N]++;
  N=1;
  return ;
}

int main(){
  ll N;
  cin >> N;
  while(N!=1){
    bunkai(N);
  }
  ll ans=0;
  for(pair<ll,ll> p:sosuu){
    ans+=floor((-1+sqrt(1+8*p.second))/2);
  }
  cout << ans << endl;
}