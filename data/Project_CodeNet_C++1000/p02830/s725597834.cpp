#include <bits/stdc++.h>
#define f(i, a, b) for(int i = a; i < (b); ++i)
#define rep(i,n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void){
  int n;
  string s, t;
  cin >> n >> s >> t;
  string ans;
  rep(i,n){
    ans+=s[i];
    ans+=t[i];
  }
  cout << ans << endl;
  return 0;
}