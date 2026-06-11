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



int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  int n = sz(s);
  reverse(all(s));
  int beki = 1, tot = 0;
  int m = 2019,ans = 0;
  vector<int> cnt(m,0);// 累積和がtotであるものが何個あるか数え上げ
  rep(i, n) {
    cnt[tot]++;
    tot +=(s[i] - '0') * beki;
    tot %= m;
    ans += cnt[tot];
    beki = (beki * 10) % m;// 次の桁が何桁目か(10の何乗か)
  }
  cout << ans << endl;
  return 0;
}
