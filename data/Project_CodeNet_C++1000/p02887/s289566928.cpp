#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  string S; cin >>S;
  int ans=1;
  rep(i,1,N) {
    if (S[i]!=S[i-1]) {ans++;}
  }
  cout <<ans <<endl;
  return 0;
}
