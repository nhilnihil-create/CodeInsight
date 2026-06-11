#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
 
  sort(v.begin(), v.end());
  
  vector<double> sum(n);
  sum[0] = (v[0] + v[1])/2.0;
  
  for(int j=0; j<n-2; j++){
    sum[j+1] = (sum[j] + v[j+2])/2.0;
  }
  
  cout << sum[n-2] << endl;
  
}