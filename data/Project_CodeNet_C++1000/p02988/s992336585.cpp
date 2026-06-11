#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<string> vs;
const ll mod = 1e9+7;
const ll inf = 1e17;
const int INF = 1e9;
const double PI = acos(-1);
#define fo(i, a, b) for (int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  int n;
  cin >> n;
  vi p(n);
  re(i, n) cin >> p[i];

  int cnt = 0;
  re(i, n-2) {
    if((p[i] < p[i+1] && p[i+1] < p[i+2]) || (p[i] > p[i+1] && p[i+1] > p[i+2])) {
        cnt++;
      }
  }
  cout << cnt << endl;

  return 0;
}
