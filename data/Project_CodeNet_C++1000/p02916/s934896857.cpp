
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n,ans = 0;
  cin >> n;
  int a[n],b[n],c[n - 1];
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n - 1) cin >> c[i];
  
  rep(i,n){
    ans += b[a[i] - 1];
    if(i == 0) continue;
    if(a[i - 1] + 1 == a[i]){
      ans += c[a[i - 1] - 1];
    }
  }
  cout << ans << endl;
  return 0;
}