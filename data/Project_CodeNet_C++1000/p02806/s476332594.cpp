#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,t[55];
  cin >> n;
  string s[55],x;
  rep(i,n) cin >> s[i] >> t[i];
  cin >> x;
  int ans = 0;
  for(int i = n-1; i >= 0; i--){
    if (s[i] == x) break;
    ans += t[i];
  }
  cout << ans << endl;
  return 0;
}
