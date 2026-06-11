#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  vector<double> u(n);
  
  for ( int i = 0; i < n; i++){
    cin >> u[i];
  }
  
  sort(u.begin(),u.end());
  
  double value = ( u[0] + u[1] ) / 2;
  
  for ( int i = 2; i < n; i++){
    value = ( value + u[i] ) / 2;
  }
  
  cout << fixed << setprecision(10) << value << endl;
 
}