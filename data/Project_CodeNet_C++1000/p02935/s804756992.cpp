#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  priority_queue<double, vector<double>, greater<double>> q;
  rep(i,0,n) {
    double v;
    cin >> v;
    q.push(v);
  }
  rep(i,0,n-1) {
    double v1 = q.top(); q.pop();
    double v2 = q.top(); q.pop();
    q.push((v1+v2)/2);
  }
  double ans = q.top();
  printf("%.10lf\n", ans);
  return 0;
}
