#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<int>;
using P = pair<int,int>;
const int INF = 1e9+7;

int main() {
  int n, k;
  cin >> n >> k;
  vec a(n);
  rep(i,n) {
    cin >> a[i];
  }

  rep(ki,k) {
    vec b(n);
    rep(i,n) {
      int l = max(0, i - a[i]);
      int r = min(n, i + a[i] + 1);
      b[l]++;
      if (r < n) b[r]--;
    }
    bool f = true;
    rep(i,n-1) {
      b[i+1] += b[i];
    }

    if (a == b) break;
    a = b;
  }

  rep(i,n) {
    cout << a[i] << endl;
  }
}
