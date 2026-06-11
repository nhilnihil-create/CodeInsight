#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 100100100;

int main(void){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  int  ans = INF;
  rep(i,105) {
    int cnt = 0;
    rep(j,n) {
      int a = x[j] - i;
      cnt += a*a;
    }
    ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}