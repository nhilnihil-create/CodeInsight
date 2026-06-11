#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using v  = vector<int>;

int main(){
  int n;cin >> n;
  v p(n);
  rep(i,n)cin>>p[i];
  int ans = 0;
  
  for(int i=1; i<=n-2; i++){
    if(p[i-1]<p[i] && p[i]<p[i+1])ans++;
    if(p[i-1]>p[i] && p[i]>p[i+1])ans++;
  }
  cout << ans << endl;
  return 0;
}
