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

int n, q;
vector<vector<int>> tree;
map<int, int> mp;
vector<int> ans;

void dfs(int s, int t, int x) {
  int temp = x;
  if (mp[s]) temp += mp[s];
  ans[s] = temp;
  for (int i: tree[s]) {
    if (i == t) continue;
    dfs(i, s, temp);
  }
}

void solve() {
  cin >> n >> q;
  tree.resize(n);
  ans.resize(n);
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  rep(i,q) {
    int p, x;
    cin >> p >> x;
    p--;
    mp[p] += x;
  }
  dfs(0, -1, 0);
  rep(i,n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  solve();
  return 0;
}