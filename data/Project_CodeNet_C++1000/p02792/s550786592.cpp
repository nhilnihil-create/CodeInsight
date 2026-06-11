#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

int cnt[10][10];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    string s = to_string(i);
    cnt[s[0] - '0'][s[sz(s) - 1] - '0']++;
  }
  ll ans = 0;
  rep(i, 10) rep(j, 10) ans += cnt[i][j] * cnt[j][i];
  cout << ans << endl;
  return 0;
}