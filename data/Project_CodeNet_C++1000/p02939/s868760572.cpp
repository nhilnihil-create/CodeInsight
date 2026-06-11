#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl;
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

//実行部
void Main()
{
  str s; cin >> s;
  ll ans = 1;
  vs flag(s.size());
  flag[0] = s.substr(0, 1);
  ll q = 1;
  for(ll i = 1;i < s.size();i++)
  {
    flag[q] = s.substr(i, 1);
    if(flag[q] == flag[q - 1])
    {
      flag[q] = s.substr(i, 2);
      i++;
    }
    q++;
  }
  if(flag[q - 1] == flag[q - 2]) q--;
  fin(q)
  return;
}

//前処理
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  Main();
  return 0;
}

/*
//test時
  g++ test.cpp -o test;./test
*/
