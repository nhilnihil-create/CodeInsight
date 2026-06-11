#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (b < a) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

int n;
set<string> ans;

void dfs(string s)
{
  if (si(s) >= n) {
    ans.em(s);
    return;
  }

  char c = s[0];
  rep(i, si(s)) chmax(c, s[i]);

  for (char x = 'a'; x <= c+1; ++x) {
    s.push_back(x);
    dfs(s);
    s.pop_back();
  }
}

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  dfs("a");

  for (auto e : ans) cout << e << endl;
  
  return (0);
}