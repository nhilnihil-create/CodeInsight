#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  rep(i,n){
    if(i%2==1){
      if(s[i]=='L' || s[i]=='U' || s[i]=='D') continue;
      ok = false;
    }
    else{
      if(s[i]=='R' || s[i]=='U' || s[i]=='D') continue;
      ok = false;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}