#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
constexpr long long mod1 = 1e9+7;
using namespace std;

vector<int> zalgo(string s){
  int i = 1, j = 0, n = s.size();
  vector<int> v(n);
  v[0] = n;
  while(i < n){
    while(i + j < n && s[j] == s[i+j]) ++j;
    v[i] = j;
    if(j == 0) ++i;
    else{
      int k = 1;
      while(k < j && k + v[k] < j){
        v[i+k] = v[k];
        ++k;
      }
      i += k;
      j -= k;
    }
  }
  return v;
}

int main(){
  int n, ans = 0; string s; cin >> n >> s;
  vector<vector<int>> v(n-1);
  vector<string> u(n-1);
  rep(i, n-1){
    string tmp = "";
    rep(j, n-i) tmp += s[i+j];
    u[i] = tmp;
  }
  rep(i, n-1) v[i] = zalgo(u[i]);
  rep(i, n-1) rep(j, v[i].size()) ans = max(ans, min(v[i][j], j));
  cout << ans << "\n";
  return 0;
}