#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  string s;ll k,i,ans = 0;cin >> s >> k;
  ll n = s.size();bool streak = false;
  if(count(s.begin(),s.end(),s[0]) == n){
    cout << n*k/2 << "\n";
    return 0;
  }
  for(i=1;i<n;i++){
    if(s[i] == s[i-1]) streak ^= true;
    else streak = false;
    ans += streak;
  }
  ans *= k;
  if(s[0] != s[n-1]){
    cout << ans << "\n";
    return 0;
  }
  bool lodd = true,rodd = true;
  for(i=1;i<n;i++){
    if(s[i] == s[i-1]) lodd ^= true;
    else break;
  }
  for(i=n-2;i>=0;i--){
    if(s[i] == s[i+1]) rodd ^= true;
    else break;
  }
  if(lodd && rodd) ans += k-1;
  cout << ans << "\n";
}