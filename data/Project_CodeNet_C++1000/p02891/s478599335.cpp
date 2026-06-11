#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
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
typedef vector<vector<bool>> vvb;
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

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

bool IsPrime(ll num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;
  ld sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
      return false;
  }
  return true;
}

void Main()
{
  str s; cin >> s;
  ll n; cin >> n;
  if(s[0] != s[s.size() - 1])
  {
    ll flag = 1;
    ll ans = 0;
    for(ll i = 1;i < s.size();i++)
    {
      if(s[i - 1] == s[i]) flag++;
      else
      {
        ans += (flag / 2) * n;
        flag = 1;
      }
    }
    ans += (flag / 2) * n;
    fin(ans);
  }
  else
  {
    ll flag = 1;
    ll ans = 0;
    vll K;
    ll h = 0;
    for(ll i = 1;i < s.size();i++)
    {
      if(s[i - 1] == s[i]) flag++;
      else
      {
        K.pb(flag);
        flag = 1;
        h = i;
      }
      if(i == s.size() - 1&&i != h)
      {
        K.pb(flag);
      }
    }
    if(s.size() == 1) K.pb(1);
    if(K.size() != 1)
    {
      ans += (K[0] / 2);
      ans += (K[K.size() - 1] / 2);
      K[0] = K[0] + K[K.size() - 1];
      K.pop_back();
      ans += (K[0] / 2 * (n - 1));
      for(ll i = 1;i < K.size();i++)
      {
        ans += (K[i] / 2 * n);
      }
      fin(ans);
    }
    else
    {
      ans += K[0] * n / 2;
      fin(ans);
    }
  }
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
