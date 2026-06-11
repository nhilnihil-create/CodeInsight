#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  int ans = INF;
  for(int i=1; i <= 100; ++i){
    int sum = 0;
    rep(j,n){
      sum += (x[j] - i) * (x[j] - i);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}