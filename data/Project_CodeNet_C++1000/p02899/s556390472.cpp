#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  rep(i,n) cin >> a[i];
  
  int ans[n];
  for(int i = 0; i < n; i++){
     ans[a[i] - 1] = i+1;
  }
  
  rep(i,n) cout << ans[i] << " ";        
}
