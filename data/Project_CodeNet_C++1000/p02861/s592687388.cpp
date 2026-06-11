#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  vector<int> x, y;
  
  cin >> n;
  
  vector<int> order(n);
  x.resize(n);
  y.resize(n);
  rep(i, n){
    cin >> x[i];
    cin >> y[i];
    order[i]=i;
  }
  
  double sum=0;
  int cnt=0;
  double xi, xj, yi, yj;
  do
  {
    rep(i, n-1){
      xi = x[order[i]];
      xj = x[order[i+1]];
      yi = y[order[i]];
      yj = y[order[i+1]];
      sum += sqrt(pow(xi-xj, 2) + pow(yi-yj, 2));
    }
    cnt++;
  } while (next_permutation(order.begin(), order.end()));
  
  
  cout << fixed << setprecision(6) << sum/cnt << endl;
  return 0;
}
