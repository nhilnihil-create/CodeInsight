#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,D,count = 0;
  double dist;
  cin >> N >> D;
  vector<double> x(N),y(N);
  rep(i,N) cin >> x[i] >> y[i];
  rep(i,N) {
    if(x[i] > D || y[i] > D) continue;
    dist = sqrt(x[i] * x[i] + y[i] * y[i]);
    if(dist <= D) count++;
  }
  cout << count << endl;
}