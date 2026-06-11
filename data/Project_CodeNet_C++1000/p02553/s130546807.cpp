#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x, y;
  ll ans = -LLONG_MAX;
  chmax(ans, a * c);
  chmax(ans, a * d);
  chmax(ans, b * c);
  chmax(ans, b * d);
  cout << ans << endl;
}