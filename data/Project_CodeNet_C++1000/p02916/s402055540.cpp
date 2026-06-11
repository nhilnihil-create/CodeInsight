#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int j=0; j<n; j++){
    cin >> b[j];
  }
  for(int k=0; k<n-1; k++){
    cin >> c[k];
  }
  
  int sum=0;
  for(int m=0; m<n; m++){
    sum += b[a[m]-1];
    if(a[m+1]-a[m]==1){
      sum += c[a[m]-1];
    }
  }
  
  cout << sum << endl;
  
}