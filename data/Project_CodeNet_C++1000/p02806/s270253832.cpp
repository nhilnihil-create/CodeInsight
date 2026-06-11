#include <bits/stdc++.h>
using namespace std;

string A[51];
int T[51];
int main() {
 int ans = 0;
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> A[i] >> T[i];
  }
  string x;
  cin >> x;
  int i;
  for(i=0; i<n; i++) {
    if(x == A[i]) break;
  }
  for(i=i+1; i<n; i++) {
    ans += T[i];
  }
    
  
  cout << ans << endl;
 return 0; 
}