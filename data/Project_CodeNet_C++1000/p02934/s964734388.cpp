#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  double a,sum = 0, ans;
  
  for ( int i = 0; i < n; i++){
    cin >> a;
    sum += 1 / a;
  }
  
  ans = 1 / sum;
  
  cout << fixed << setprecision(10) << ans << endl;
 
}