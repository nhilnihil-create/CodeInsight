#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;
const double PI = acos(-1);


void solve() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double ang = abs((m*6) - (h * 30 + m * 0.5));
  double ans = sqrt(pow(a,2) + pow(b,2) - 2.0 * a * b * cos(ang * PI / 180));
  cout << setprecision(12) << ans << endl;
}

int main() {
  solve();
  return 0;
}