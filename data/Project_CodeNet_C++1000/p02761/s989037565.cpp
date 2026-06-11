#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,M; cin >>N >>M;
  string ans;
  if (N==1) {
    ans="0";
  } else {
    ans="1";
    ans.append(N-1,'0');
  }
  vector<int> check(N);
  rep(i,0,M) {
    int s,c; cin >>s >>c;
    if (check[s-1]==0) {
      check[s-1]=c;
    } else if (check[s-1]!=c) {
      cout <<-1 <<endl;
      return 0;
    }
    ans[s-1]=c+'0';
  }
  if (ans.size()==1) {
    cout <<ans <<endl;
  } else {
    if (ans[0]!='0') {
      cout <<ans <<endl;
    } else {
      cout <<-1 <<endl;
    }
  }
  return 0;
}
