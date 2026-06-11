#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll l = a - (a / c + a / d) + a / lcm(c, d);
  ll r = b - (b / c + b / d) + b / lcm(c, d);
  cout << r - l << endl;
}

int main() {
  solve();
  return 0;
}