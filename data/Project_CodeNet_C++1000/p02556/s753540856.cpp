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
  vector<int> xd(n), yd(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xd[i] = x + y;
    yd[i] = x - y;
  }

  sort(xd.begin(), xd.end());
  sort(yd.begin(), yd.end());
  int ans = max(xd.back() - xd[0], yd.back() - yd[0]);
  cout << ans << endl;
  
}