
// Problem : A - Plural Form
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Macros

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define db long double
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int, int>
#define mii map<pii, int>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(x) (int) x.size()
#define mod 1000000007
#define EPS 1e-9
#define inf 1e10
#define PI acos(-1.0)
#define int long long
#define N 100005

// Solution

void solve() {
  string s;
  cin >> s;
  if (s[sz(s) - 1] == 's')
    s += "es";
  else
    s += 's';
  cout << s;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

  int tests;
  tests = 1;
  // cin>>tests;

  for (int test = 1; test <= tests; test++) {
    // cout<<"Case #"<<test<<": ";
    solve();
  }

  return 0;
}