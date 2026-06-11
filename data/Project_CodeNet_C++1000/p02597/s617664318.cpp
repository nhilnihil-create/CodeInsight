#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int w,r,n;
  cin >> n;
  string s;
  cin >> s;
  r=w=0;
  rep(i,s.size()){
    if(s[i]=='R') r++;
  }
  int ans = n;
  rep(i,s.size()){
    ans = min(ans, max(r,w));
    if(s[i]=='W') w++;
    else r--;
    // cout << ans << endl;
  }
  ans = min(ans, max(r,w));
  cout << ans << endl;
  
  return 0;
    

}
