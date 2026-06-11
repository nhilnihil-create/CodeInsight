#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

ll pow_mod(ll a, ll n, ll MOD){
  ll m[60]; m[0]=a; // m[i] : a^(2^i)をMODで割った余り
  rep(i,59) m[i+1] = (m[i]*m[i])%MOD;

  ll retval = 1;
  bitset<60> s(n);
  rep(i,60) if (s.test(i)) (retval *= m[i]) %= MOD;

  return retval; 
}

int main(){
  int N; cin >> N;
  vector<ll> cnt(N);
  int D; 
  ll MOD = 998244353;
  ll ans = 1;
  rep(i,N) {
    cin >> D;
    if (i==0 && D!=0) ans = 0;
    cnt[D]++;
  }

  bool is_tree = true;
  int tot = 0;
  rep(i,N){
    if (cnt[i]==0 && tot<N) is_tree = false;
    tot += cnt[i];
  }
  if (is_tree==false || cnt[0]!=1) ans = 0;


  rep(i,N-1){
    if (cnt[i]==0) break;
    (ans *= pow_mod(cnt[i],cnt[i+1],MOD))%= MOD;
  }
  cout << ans << endl;

  

  // cout << fixed << setprecision(10);
  
  return 0;
}
