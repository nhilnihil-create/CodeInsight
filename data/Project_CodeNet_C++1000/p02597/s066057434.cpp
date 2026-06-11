#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans=0;
  int r=0;
  for(int i=0;i<n;i++) if(s[i]=='R') r++;
  for(int i=0;i<r;i++) if(s[i]=='W') ans++;
  
    
  cout << ans << endl;
  return 0;
}
