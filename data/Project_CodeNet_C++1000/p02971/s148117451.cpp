#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
 
  vector<int> b(n);
  for(int j=0; j<n; j++){
   b[j] = a[j];
  }
  
  sort(b.begin(), b.end());
  
  if(b[n-2]==b[n-1]){
    for(int k=0; k<n; k++){
      cout << b[n-1] << endl;
    }
  }
  else{
    for(int l=0; l<n; l++){
      if(a[l]==b[n-1]){
        cout << b[n-2] << endl;
      }
      else{
        cout << b[n-1] << endl;
      }
    }
  }
  
}
