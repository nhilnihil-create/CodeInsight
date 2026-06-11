#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n;
  cin >> n;
  vi w(n);
  rep(i,n) cin >> w[i];
  int ans = 10000000;
  rep(i,n){
    int sum1 = 0,sum2 = 0;
    rep(j,n){
      if(j<i) sum1 += w[j];
      else sum2 += w[j];
    }
    ans = min(ans, abs(sum1-sum2));
  }
  cout << ans << endl;
}
