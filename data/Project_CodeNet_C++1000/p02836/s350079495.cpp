#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  int n=s.size();
  string t=s.substr(0,n/2);
  reverse(rng(s));
  string u=s.substr(0,n/2);
  int ans=0;
  rep(i,n/2) {
    if(s[i]!=t[i]) ans++;
  }
  cout << ans << endl;
}