#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5050;
ll p[N], c[N];
int k, n;
int see[N];
int len, start;

ll calc(int pos, int count) {
  ll ans = 0;
  for (int i=0; i<count; ++i) {
    ans += c[pos];
    pos = p[pos];
  }
  return ans;
}

ll solve(int beg) {
  memset(see, 0, sizeof see);

  int pos = beg;
  for (int i=1; i<=n+1; ++i) {
    if (see[pos]) {
      len = i-see[pos];
      start = pos;
      break;
    }
    see[pos] = i;
    pos=p[pos];
  }
  ll ans = -1e9;
  ll cur = 0;
  pos = beg;
  ll rep = 0;
  for (int i=0; i<min(n,k); ++i) {
    if (i+1 == see[start]) {
      rep = cur;
    }
    cur += c[pos];
    pos = p[pos];
    ans = max(ans, cur);
  }

  pos = start;
  int iloop = (k-see[start]+1-len)/len;
  rep += calc(start, len)*iloop;
  for (int i=max(1, see[start]+iloop*len); i<=k; ++i) {
    //cerr << " I " << i << endl;
    rep += c[pos];
    ans = max(rep, ans);
    pos = p[pos];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> p[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> c[i];
  }
  ll ans = -1e9;
  for (int i=1; i<=n; ++i) {
    ans = max(ans, solve(i));
  }
  cout << ans << "\n";
  return 0;
}
