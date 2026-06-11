#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<double> p(n);
  rep(i, n){
    double in;
    cin >> in;
    p.at(i) = (double)(in+1)/2;
  }
  vector<double> sums(n+1, 0);
  rep(i, n) sums.at(i+1) = sums.at(i) + p.at(i);
  double ans = 0;
  rep2(i, k, n+1){
    double add = sums.at(i) - sums.at(i-k);
    ans = max(ans, add);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}