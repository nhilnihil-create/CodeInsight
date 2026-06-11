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
  int k;
  cin >> k;
  vector<bool> used(k);
  int ans = 0;
  int cur = 7;

  while (true) {
    ans++;
    cur %= k;
    if (cur == 0) break;
    if (used[cur]) {
      cout << -1 << endl;
      return 0;
    }
    used[cur] = true;
    cur *= 10;
    cur += 7;
  }
  cout << ans << endl;
}