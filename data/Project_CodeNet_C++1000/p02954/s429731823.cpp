#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n=s.size();
  vector<int> ans(n,0);
  s+='R';
  int now=0;
  while(now<n-1){
      int r=0,l=0;
      while(!(s[now]=='L'&&s[now+1]=='R')){
          if(s[now]=='R') r++;
          else l++;
          now++;
      }
      l++;
      int rl=now-l;
      if((r+l)%2==0){
          ans[rl]=((r+l)/2);
          ans[rl+1]=((r+l)/2);
          now++;
      }
      else if(r%2==1){
          ans[rl]=(((r+l)/2)+1);
          ans[rl+1]=((r+l)/2);
          now++;
      }
      else{
          ans[rl]=(((r+l)/2));
          ans[rl+1]=(((r+l)/2)+1);
          now++;
      }
  }
  rep(i,n) cout << ans[i] << endl;
}