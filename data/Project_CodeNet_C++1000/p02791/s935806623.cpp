#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  int ans=0;
  int mini=1e9;
  rep(i,n){
    mini = min(mini, p[i]);
    if(mini == p[i]) ans++;
  }
  cout << ans << endl;
  return 0;  
}