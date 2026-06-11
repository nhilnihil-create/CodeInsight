#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
#define digits 61
typedef long long ll;
const long long MOD = 1e9+7;

int main(){
  int n;cin>>n;
  vector<ll> one(digits,0);
  
  REP(i,n){
    ll a;cin>>a;
    REP(j,digits){
      if(a%2) one.at(j)++;
      a/=2;
    }
  }

  ll ans=0;
  REP(i,digits){
    ll tmp=(ll)pow(2,i)%MOD;
    tmp=(tmp*(n-one.at(i)))%MOD;
    tmp=(tmp*one.at(i))%MOD;
    ans=(ans+tmp)%MOD;
  }
  cout<<ans;
}