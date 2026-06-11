#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  int n;cin >> n;
  ll ans = 0;
  vector<string> s(n);
  map<string,int> m;
  rep(i,n){
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
    m[s[i]] += 1;
  }
  rep(i,n){
    if(m[s[i]] >= 2){
      ans += m[s[i]]-1;
      m[s[i]] -= 1;
    }
  }
  cout << ans << endl;
  return 0;
}