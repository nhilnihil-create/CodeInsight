#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s,t;
  cin>>s>>t;
  int n = s.size();
  int m = t.size();
  vector<vector<int>> a(26);
  
  rep(i,n) a[s[i]-'a'].pb(i);
  rep(i,n) a[s[i]-'a'].pb(i+n);
  
  int res = 0;
  ll ans = 0;
  rep(i,m){
    int p = t[i]-'a';
    if(a[p].size()==0){
      cout << -1 << endl;
      return 0;
    }
    res = *lower_bound(a[p].begin(),a[p].end(),res)+1;
    if(res>=n){
      res -= n;
      ans += n;
    }
  }
  ans += res;
  cout << ans << endl;
} 