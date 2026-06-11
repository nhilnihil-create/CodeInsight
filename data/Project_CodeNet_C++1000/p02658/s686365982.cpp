#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
constexpr double EPS = 1e-12;

int main(){
  int n;
  cin >> n;
  vector<int64> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i){
    if(a[i] == 0LL){
      cout << 0 << endl;
      return 0;
    }
  }
  double keta = 0;
  for(int i = 0; i < n; ++i){
    keta += log10(a[i]);
  }
  if(keta > 18 + EPS){
    cout << -1 << endl;
    return 0;
  }
  int64 ans = 1;
  for(int i = 0; i < n; ++i){
    ans *= a[i];
  }
  if(ans > 1000000000000000000LL) cout << -1 << endl;
  else cout << ans << endl;
}