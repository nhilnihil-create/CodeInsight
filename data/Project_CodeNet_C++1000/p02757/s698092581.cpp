#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

int main(){
  int N,P; cin>>N>>P;//O(nlog(n)) cuz n=2*10^5;
  string S; cin>>S;

  if(10%P==0){
    ll ans = 0;
    rep(r,N){
      if((S.at(r)-'0')%P==0){
        ans += r+1;
      }
    }
    cout<<ans<<endl;
    return 0;
  }

  vector<ll> dp(N+1);
  int ten = 1;
  for(int i = N-1; i >= 0; i--){
    int a = (S.at(i)-'0')*ten%P;
    dp.at(i) += (dp.at(i+1)+a) % P;
    ten *= 10; ten %= P;
  }
  map<ll,ll> m;
  for(auto i: dp){
    if(m.count(i))m[i]++;
    else m[i]=1;
  }

  ll res = 0;
  for(auto p: m){
    ll num = p.second;
    res += (num-1)*num/2;
  }

  cout<<res<<endl;
}