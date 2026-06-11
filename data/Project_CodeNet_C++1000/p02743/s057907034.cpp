#include <bits/stdc++.h>
#define a(v) (v.begin(), v.end())
#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (ll i = a; i > b; i--)
#define intlimit 2e9 + 100
#define longlimit 8e18 + 100
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = 2 * a * b + 2 * a * c + 2 * b * c;
  ll y = a * a + b * b + c * c;
  if (c - b - a <= 0)
  {
    cout << "No\n";
    return 0;
  }
  if (x < y)
  {
    cout << "Yes\n";
  }
  else
  {
    cout << "No\n";
  }
}