#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
 
  vector<double> b(n);
  for(int j=0; j<n; j++){
    b[j] = 1.0 / a[j];
  }
  
  double sum=0.0;
  for(int k=0; k<n; k++){
    sum += b[k];
  }
  
  cout << fixed << setprecision(15);
  
  cout << 1/sum << endl;
  
}
