#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  string S; cin >>S;
  string ans="No";
  if (S.size()%2==0) {
    string T="";
    rep(i,0,S.size()/2) {
      T+="hi";
    }
    if (S==T) {
      ans="Yes";
    }
  }
  cout <<ans <<endl;
  return 0;
}
