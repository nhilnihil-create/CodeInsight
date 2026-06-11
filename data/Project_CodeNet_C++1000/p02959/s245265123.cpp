#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<int> b(n);
  for (int i = 0;i < n+1;i++){
    cin >> a[i];
  }
  for (int i = 0;i < n;i++){
    cin >> b[i];
  }
  
  long long ans = 0;
  
  for (int i = 0;i < n;i++){
    if (b[i] >= a[i]){
      b[i] -= a[i];
      ans += a[i];
      a[i] = 0;
      if (b[i] >= a[i+1]){
        b[i] -= a[i+1];
        ans += a[i+1];
        a[i+1] = 0;
      }
      else{
        a[i+1] -= b[i];
        ans += b[i];
        b[i] = 0;
      }
    }
    else{
      a[i] -= b[i];
      ans += b[i];
      b[i] = 0;
    }
  }
  
  cout << ans << endl;
}