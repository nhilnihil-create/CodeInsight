#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  long long ans = 1000, kabu = 0;
  rep(i,n) {
    if(i == n-1) {
      ans += kabu * a[i];
      break;
    }else if(a[i] < a[i+1] && kabu == 0) {
      kabu = ans / a[i];
      ans -= kabu * a[i];
    }else if(a[i] > a[i+1] && kabu != 0) {
      ans += kabu * a[i];
      kabu = 0;
    }
  }
  cout << ans << endl;
}