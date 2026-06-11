#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;


int main(){
  string s; cin >> s;
  int n = s.size()+1;
  vector<int> a(n,0);
  for(int i = 1; i < n; i++){
    if(s[i-1] == '<'){
      a[i] = max(a[i-1]+1, a[i]);
    }
  }
  for(int i = n-2; i >= 0; i--){
    if(s[i] == '>'){
      a[i] = max(a[i+1]+1, a[i]);
    }
  }
  ll ans = 0;
  rep(i,n){
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
