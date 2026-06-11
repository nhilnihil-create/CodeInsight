#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> s;
  n = s.size();
  vector<int> ans(n,1);
//  cout << n << endl;
  rep(i,n-1){
    if(s[i]=='R'&& s[i+1]=='R') {
      ans[i+2] += ans[i];
      ans[i] =0;
    }
    if(s[i]=='R'&& s[i+1]=='L') continue;
  }
  for(int i=n-1; i>=1; i--){
    if(s[i]=='L'&& s[i-1]=='L') {
      ans[i-2] += ans[i];
      ans[i] =0;
    }
    if(s[i]=='L'&& s[i-1]=='R') continue;
  }
  rep(i,n) cout << ans[i] << ' ';
  cout << endl;
}
