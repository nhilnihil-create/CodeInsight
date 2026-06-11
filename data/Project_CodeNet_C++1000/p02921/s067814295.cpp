
// Problem: A - Tenki
// Contest: AtCoder - AtCoder Beginner Contest 139
// URL: https://atcoder.jp/contests/abc139/tasks/abc139_a
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
	string s,t;
	cin>>s>>t;
	cout<<(s[0]==t[0])+(s[1]==t[1])+(s[2]==t[2]);
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  //cin >> t;
  while (t--)
    solve();
  return 0;
}