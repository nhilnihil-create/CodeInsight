#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int64_t a[n+1];
  int64_t b[n+1];
  int64_t c[n];
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  for(int i = 1; i <= n-1; i++){
    cin >> c[i];
  }
  
  int64_t ans = b[a[1]];
  int64_t tmp = a[1];
  for(int i = 2; i <= n; i++){
    ans += b[a[i]];
    if((tmp + 1) == a[i] /*&& a[i] != n*/){
      ans += c[tmp];
    }
    tmp = a[i];
  }
  
  cout << ans << endl;
    
}