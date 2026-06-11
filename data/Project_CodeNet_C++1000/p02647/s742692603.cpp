#include<bits/stdc++.h>
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  rep(i, k) {
    vector<int> sum(n + 1);
    rep(i, n) {
      int low = max(0, i - a[i]);
      int high = min(n , i + a[i] + 1);
      sum[low]++;
      sum[high]--;
    }

    int cur = 0;
    bool ok = true;
    rep(i, n) {
      cur += sum[i];
      a[i] = cur;
      if (cur != n) ok = false;
    }

    if (ok) break;
  }

  rep(i, n) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
}