#include <iostream>
#include <vector>
#include <string>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

string jan = "rsp";
int main(){
  int n, k, r, s, p;
  string t;
  cin >> n >> k;
  cin >> r >> s >> p;
  cin >> t;
  int ans = 0;
  rep(i, n){
    if (i - k < 0){
      if (t[i] == jan[0]) ans += p;
      else if (t[i] == jan[1]) ans += r;
      else if (t[i] == jan[2]) ans += s;
    }
    else {
      if (t[i] == t[i-k]){
        t[i] = 'a';
        continue;
      }
      if (t[i] == jan[0]) ans += p;
      else if (t[i] == jan[1]) ans += r;
      else if (t[i] == jan[2]) ans += s;
    }
  }
  cout << ans << endl;
  
  return 0;
}