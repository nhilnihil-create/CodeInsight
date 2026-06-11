#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
int main(){
  string s,t;cin>>s>>t;
  set<char>ss,tt;
  rep(i,0,s.size()){
    ss.insert(s[i]);
  }
  rep(i,0,t.size()){
    tt.insert(t[i]);
  }
  for(auto u:tt){
    if(!ss.count(u)){
      cout<<-1<<endl;return 0;
    }
  }
  vvll m(26,vll(0));
  rep(i,0,s.size()){
    m[s[i]-'a'].push_back(i+1);
  }
  ll ans=0,now=0;
  rep(i,0,t.size()){
    auto it=upper_bound(m[t[i]-'a'].begin(),m[t[i]-'a'].end(),now);
    if(it==m[t[i]-'a'].end()){
      ans+=m[t[i]-'a'][0]+s.size()-now;
      now=m[t[i]-'a'][0];
    }
    else {
      ans+=*it-now;
      now=*it;
    }

  }
  cout<<ans<<endl;
}

