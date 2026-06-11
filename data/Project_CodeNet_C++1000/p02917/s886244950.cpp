#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int b[n-1];
  rep(i,n-1) cin >> b[i];
  
  int ans = b[0];
  for(int i = 1; i < n-1; i++)
  {
    ans += min(b[i],b[i-1]);
  }
  ans += b[n-2];
  
  cout << ans << endl;
}