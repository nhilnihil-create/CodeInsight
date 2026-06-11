#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int K; cin >>K;
  int ans=0;
  rep_eq(a,1,K) {
    rep_eq(b,1,K) {
      rep_eq(c,1,K) {
        ans+=gcd(gcd(a,b),c);
      }
    }
  }
  cout <<ans <<endl;
  return 0;
}
