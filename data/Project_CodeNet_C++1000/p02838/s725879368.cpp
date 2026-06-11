#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;
const long long MOD = 1e9+7;

int main(){
  int n;cin>>n;
  vector<ll> zero(61,0),one(61,0);
  
  REP(i,n){
    ll a;cin>>a;
    REP(j,61){
      (a%2?one:zero).at(j)++;
      a/=2;
    }
  }

  ll ans=0;
  REP(i,61){
    ll tmp=(ll)pow(2,i)%MOD;
    tmp*=zero.at(i);
    tmp%=MOD;
    tmp*=one.at(i);
    tmp%=MOD;
    ans+=tmp;
    ans%=MOD;
  }
  cout<<ans;
}