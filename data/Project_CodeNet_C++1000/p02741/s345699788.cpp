#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<string> vs;
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  vi v = {1, 1, 1, 2, 1, 2, 1, 5,
          2, 2, 1, 5, 1, 2, 1, 14,
          1, 5, 1, 5, 2, 2, 1, 15,
          2, 2, 5, 4, 1, 4, 1, 51};
  int n;
  cin >> n;

  cout << v[n-1] << endl;

  return 0;
}
