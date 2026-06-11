#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

vector<ll> Divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0){
      res.push_back(i);
      if(i*i != n) res.push_back(n/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

ll DivisorCnt(ll n){
  if(n < 1) return 0;
  map<ll, ll> mp;
  ll cnt = 0;
  while(n%2 == 0){
    n /= 2;
    cnt++;
  }
  if(cnt != 0) mp[2] = cnt;
  for(ll i = 3; i*i <= n; i += 2){
    cnt = 0;
    while(n%i == 0){
      n /= i;
      cnt++;
    }
    if(cnt != 0) mp[i] = cnt;
  }
  if(n != 1) mp[n] = 1;
  ll res = 1;
  for(auto i : mp){
    res *= (i.second+1);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  ll ans = DivisorCnt(N-1)-1; // 約数のうち1は除く
  vector<ll> D = Divisor(N);
  for(auto i : D){
    if(i == 1) continue; // 約数のうち1は除く
    ll tmp = N;
    while(tmp%i == 0){
      tmp /= i;
    }
    if(tmp == 1 || tmp%i == 1) ans++;
  }
  cout << ans << endl;
}
