#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

void NO() {
  cout << "No" << endl;
  exit(0);
}

const int N = 1 << 19;
int s[N];

int idx = 1;
vector<int> adj[N];
int dep[N], par[N];
VI at[30];

string ty[N];
string cur;

multiset<int> ss;
int ans[N], ids[N];

const int INF = 1e9 + 10;

int build(int u, int sub, int d, int p) {
  dep[u] = d;
  par[u] = p;

  int ht = sub;
  cur.push_back(ht + '0');

//  int lim = p == -1 ? INF : ans[p];
//  auto it = ss.lower_bound(lim);
//  if (it == ss.begin()) NO();
//  it--;
//  ans[u] = *it;
//  ss.erase(it);

  for (int i = 0; i < sub; i++) {
    int v = idx++;
    adj[u].push_back(v);
    build(v, sub - 1 - i, d + 1, u);
  }

  at[d].push_back(u);

  ty[u] = cur;
  reverse(ty[u].begin(), ty[u].end());
  cur.pop_back();

  return ht;
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  int sz = 1 << n;
  for (int i = 0; i < sz; i++) {
    cin >> s[i];
    ss.insert(s[i]);
  }

//  sort(s, s + sz);

  build(0, n, 0, -1);


  iota(ids, ids + sz, 0);
  sort(ids, ids + sz, [&](int u, int v) {
    return ty[u] > ty[v];
  });
  for (int i = 0; i < sz; i++) {
    int u = ids[i];
    int lim = par[u] == -1 ? INF : ans[par[u]];
    auto it = ss.lower_bound(lim);
    if (it == ss.begin()) NO();
    it--;
    ans[u] = *it;
    ss.erase(it);
  }

//  idx = 0;
//  for (int d = 29; d >= 0; d--) {
//    reverse(at[d].begin(), at[d].end());
//    for (int u: at[d]) {
//      ans[u] = s[idx++];
//    }
//  }

  for (int u = 0; u < sz; u++) {
    for (int v: adj[u]) {
      if (ans[v] >= ans[u]) NO();
    }
  }

  cout << "Yes" << endl;

  return 0;
}
