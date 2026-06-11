#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i,m) {
    int x;
    string y;
    cin >> x >> y;
    x--;
    p[i] = x;
    s[i] = y;
  }
  vector<bool> check(n);
  vector<int> cnt(n);
  rep(i,m) {
    if (check[p[i]]) continue;

    if (s[i] == "AC") check[p[i]] = true;
    else cnt[p[i]]++;
  }
  int res1 = 0;
  int res2 = 0;
  rep(i,n) {
    if (check[i]) {
      res1++;
      res2 += cnt[i];
    }
  }
  cout << res1 << " " << res2 << endl;
}

int main() {
  solve();
  return 0;
}