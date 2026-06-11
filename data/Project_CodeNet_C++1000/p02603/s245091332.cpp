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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1000;
  for (int i = 1; i < n; ++i) {
    ll stocks = 0;
    if (a[i] > a[i - 1]) {
      stocks = ans / a[i - 1];
      ans %= a[i - 1];
      ans += a[i] * stocks; 
    }

  }
  cout << ans << endl;
}