#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

ll MOD = 1000000007;
ll n;

ll Pow(ll m){ //m^nを返す
  ll ret = 1;
  rep(i,n){
    ret *= m;
    ret %= MOD;
  }
  ret %= MOD;
  //cout << "m=" << m << ",ret = " << ret << endl;
  return ret;
}

vector<pair<ll, ll>> Prime_Factorize(ll n){
  vector<pair<ll, ll>> ans;
  for (ll a=2; a*a<=n; a++){
    if (n%a != 0) continue;
    ll ex = 0; //指数
    while(n%a == 0){
      ex++;
      n /= a;
    }
  ans.push_back({a, ex});
  }
  if (n != 1) ans.push_back({n,1});
  return ans;
}

int main(){
  ll n; cin >> n;
  const auto res = Prime_Factorize(n);
  ll ans = 0;
  for (auto p:res){
    ll exp = p.second;
    //cout << exp << "," << endl;
    ll lim = 0;
    for (int i=1; i<=exp; i++){
      lim += i;
      if (exp == 1){
        ans += 1;
        break;
      }
      if (lim > exp){
        ans += i-1;
        break;
      }
    }
  }
  cout << ans << endl;
}

