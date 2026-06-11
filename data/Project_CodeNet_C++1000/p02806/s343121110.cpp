#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  string x;
  vector<string> s(n);
  vector<int> t(n);
  int ans = 0;
  rep(i, n){
    cin >> s[i] >> t[i];
    ans += t[i];
  }
  cin >> x;
  rep(i, n){
    ans -= t[i];
    if(s[i] == x) break;
  }
  cout << ans << endl;
  return 0;
}
