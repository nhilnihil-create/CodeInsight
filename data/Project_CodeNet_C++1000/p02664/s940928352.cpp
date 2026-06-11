#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  string T; cin >>T;
  string ans="";
  rep(i,0,T.size()) {
    if (T[i]=='?') {
      ans.push_back('D');
    } else {
      ans.push_back(T[i]);
    }
  }
  cout <<ans <<endl;
  return 0;
}
