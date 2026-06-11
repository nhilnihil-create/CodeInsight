
// Problem: C - A x B + C
// Contest: AtCoder - AtCoder Beginner Contest 179
// URL: https://atcoder.jp/contests/abc179/tasks/abc179_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll long long int
#define ii int
#define du double
#define jmp "\n"
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define printv(v)     \
  for (auto x : v)    \
    cout << x << " "; \
  cout << jmp;
#define vi vector<int>
#define vb vector<bool>
#define ump unordered_map
#define SORT(v) sort(v.begin(), v.end())
#define REV(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define SET(x, a) memset(x, a, sizeof(x))
#define si(x) x.size()
#define ff first
#define ss second
#define iin insert
#define deb(x) cout << "test " << #x << "=" << x << jmp
#define deb2(x, y) cout << "test " << #x << "=" << x << "," << #y << "=" << y << jmp
using namespace std;
const ll nax = 1e5 + 5;

void solve()
{
  ll n;
  cin >> n;
  ll ctr = 0;
  for (ll j = 1; j < n; j++)
  {
    for (ll i = 1; i * j < n; i++)
      if (n - (i * j) > 0)
        ctr++;
  }
  cout << ctr << jmp;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}