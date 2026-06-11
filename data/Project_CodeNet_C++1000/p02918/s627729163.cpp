#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;


int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll cnt=0;
  rep(i,0,n-1){
    if(s[i]==s[i+1]) cnt+=1;
  }
  ll ans;
  if(cnt+2*k<n) ans=cnt+2*k;
  else ans=n-1;
  cout << ans << endl;
  

  return 0;
}
