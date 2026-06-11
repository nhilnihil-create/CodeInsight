#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> x(N); vector<int> y(N);
  for (int i =0; i<N; i++) cin >> x[i] >> y[i];
  
  double ans =0;
  for (int i =0; i<N; i++) {
    for (int j =i+1; j<N; j++) {
      double tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      ans += sqrt(tmp);
    }
  }    
  
  ans *= (double)2 / N;                                                     
  cout << fixed << setprecision(12) << ans << endl;  
}