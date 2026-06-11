#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repto(i, n) for(int i = 0; i <= (n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  ll ans = 1;
  vector<vector<int> > v(N);
  vector<int> a(N);
  vector<int> b(N);
  vector<int> d(N);
  vector<bool> seen(N, false);
  queue<int> que;
  rep(i, N-1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    v[a[i]].pb(b[i]);
    v[b[i]].pb(a[i]);
  }
  int s = 0;
  que.push(s);
  seen[s] = true;
  d[s] = 0;
  ans *= ll(K);
  int tmp = K;
  int cnt = 0;
  while(!que.empty()) {
    s = que.front();
    que.pop();
    if (d[s] == 0)
      tmp = K-1;
    else
      tmp = K-2;
    for (int i = 0; i < v[s].size(); i++) {
      int t = v[s][i];
      if (seen[t] == false) {
        que.push(t);
        seen[t] = true;
        d[t] = d[s]+1;
        // cout << tmp << ' ';
        ans *= (ll)tmp;
        ans %= MOD;
        tmp--;
      }
    }
    // cout << s << endl;
  }
  cout << ans << endl;
}
