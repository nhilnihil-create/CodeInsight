#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  priority_queue<double, vector<double>, greater<double>> Q;
  double q, ans=0;
  for (int i=0; i<N; i++) {
    cin >> q;
    Q.push(q);
  }
  while (Q.size()>1) {
    double p1, p2;
    p1=Q.top();
    Q.pop();
    p2=Q.top();
    Q.pop();
    ans=(p1+p2)/2;
    Q.push((p1+p2)/2);
  }
  cout << ans << endl;
}
