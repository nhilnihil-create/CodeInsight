#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,K; cin >>N >>K;
  int ans=0;
  if (K!=1) {
    ans=N-K;
  }
  cout <<ans <<endl;
  return 0;
}
