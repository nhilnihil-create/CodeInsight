
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  int n;
  cin >> n;
  int a[n];
  ll ans = 0;
  rep(i,n) cin >> a[i];
  rep(i,n){
    for(int j = i; j < n; j++){
      if(i == j) continue;
      ans += a[i] * a[j];
    }
  }
  cout << ans << endl;
  return 0;
}
