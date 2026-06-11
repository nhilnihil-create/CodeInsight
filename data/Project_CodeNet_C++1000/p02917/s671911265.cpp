#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> b(n-1);
  for(int i=0; i<n-1; i++){
    cin >> b[i];
  }
 
  vector<int> a(n);
  a[0]=b[0];
  a[n-1]=b[n-2];
  
  for(int j=1; j<n-1; j++){
    a[j]=min(b[j-1], b[j]);
  }
  
  int64_t sum=0;
  for(int k=0; k<n; k++){
    sum += a[k];
  }
  
  cout << sum << endl;
}