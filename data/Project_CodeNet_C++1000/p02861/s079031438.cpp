#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  
  int fact = 1;
  for(int i=1; i<=n; i++) fact *= i;
  
  //n*(n-1)/2 組合せの数
  //(n-1)*fact 2点を結ぶ経路の総数
  double dist, sum = 0;
  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      sum += dist * ((n-1)*fact) / (n*(n-1)/2);
    }
  }
  
  cout << fixed << setprecision(10) << sum/fact << endl;
  return 0;
}
