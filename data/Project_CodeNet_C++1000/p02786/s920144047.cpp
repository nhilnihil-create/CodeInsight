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
  ll h;
  cin >> h;
  ll ans = 0;
  ll num = 1;
  while (h > 0) {
    ans += num;
    num *= 2;
    h /= 2;
  }

  cout << ans << endl;
}