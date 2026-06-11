#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int H,W,N; cin >>H >>W >>N;
  int ans=ceil(N/float(max(H,W)));
  cout <<ans <<endl;
  return 0;
}
