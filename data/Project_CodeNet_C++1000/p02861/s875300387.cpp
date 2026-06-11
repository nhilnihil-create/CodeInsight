#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n){
    cin >> x[i] >> y[i];
  }
  vector<int> order(n);
  rep(i, n) order[i] = i;

  double sum = 0;
  int count = 0;
  do{
    rep(i, n-1){
      int dx, dy;
      dx = x[order[i]] - x[order[i+1]];
      dy = y[order[i]] - y[order[i+1]];
      sum += sqrt(dx * dx + dy * dy);
    }
    count++;
  } while(next_permutation(order.begin(), order.end()));
  sum = sum / count;
  cout << fixed << setprecision(7) << sum << endl;
  return 0;
}