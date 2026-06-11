#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  ll n, p; cin >> n >> p;
  string s; cin >> s;

  //p = 2, 5 の場合
  if(p == 2 || p == 5){
    ll ans = 0;
    rep(i, 0, n){
      if((s[i] - '0') % p == 0 ) ans += i+1;
    }
    cout << ans << endl;
    return 0;
  }

  //p != 2, 5 の場合
  vector<int> d(n+1);
  d[n] = 0;
  ll cnt = 1;
  for(int i = n-1; i >= 0; i--){
    ll a = (s[i]-'0')*cnt % p;
    d[i] = (d[i+1] + a) % p;
    cnt *= 10;
    cnt %= p;
  }

  //組み合わせの数を計算
  vector<int> sum(p, 0);
  ll ans = 0;
  Rep(i, 0, n){
    ans += sum[d[i]];
    sum[d[i]]++;
  }

  cout << ans << endl;

  return 0;
}
