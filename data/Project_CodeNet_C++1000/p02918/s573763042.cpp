#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,k,ans = 0;
  string s;
  cin >> n >> k >> s;
  rep(i,0,n){
    if((i == 0 && s[i] == 'L')||(i == n-1 && s[i] == 'R')) continue;
    if(s[i] == 'L' && s[i] == s[i-1]) ans++;
    if(s[i] == 'R' && s[i] == s[i+1]) ans++;
  }
  ans += 2*k;
  ans = min(ans,n-1);
  cout << ans << endl;
}