#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  string s;
  int k;
  cin >>s >>k;
  int n = s.size();
  int cnt = 1;
  rep(i,n-1){
    if(s[i]==s[i+1]) cnt++;
    else break;
  }
  if(cnt==n){
    cout << (ll)n*k/2 << endl;
    return 0;
  }
  ll ans = 0;
  rep(i,n-1){
    if(s[i]==s[i+1]){
      ans++;
      s[i+1]='*';
    }
  }
  ans *= k;
  if(s[0]==s[n-1]&&cnt%2==1) ans+=k-1;
  cout << ans << endl;
  return 0;
}
