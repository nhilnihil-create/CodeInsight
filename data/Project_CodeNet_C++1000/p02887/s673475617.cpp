#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 1;
  string s;
  cin >> n >> s;
  rep(i,1,n){
    if(s[i] != s[i-1]) ans++;
  }
  cout << ans << endl;
}