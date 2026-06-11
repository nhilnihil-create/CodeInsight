#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  for (int i =0; i<N; i++) {
    int a,b;
    cin >> a >> b;
    x.at(i) = a; y.at(i) = b;
  }
  
  double ans =0;
  for (int i =0; i<N; i++) {
    for (int j =i+1; j<N; j++) {
      double r = sqrt((x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j))); 
      ans += r;
    }
  }
  ans = ans * 2 / N;
  cout << fixed << setprecision(10) << ans << endl;
}