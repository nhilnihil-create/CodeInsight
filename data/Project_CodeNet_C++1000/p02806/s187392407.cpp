#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<string> s(N);
  vector<int> t(N);
  rep(i,0,N) {cin >>s[i] >>t[i];}
  string X; cin >>X;
  int idx=0;
  rep(i,0,N) {
    if (s[i]==X) {
      idx=i+1;
    }
  }
  int ans=0;
  rep(i,idx,N) {
    ans+=t[i];
  }
  cout <<ans <<endl;
  return 0;
}
