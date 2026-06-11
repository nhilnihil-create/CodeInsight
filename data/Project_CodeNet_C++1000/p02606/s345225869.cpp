#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int L,R,d; cin >>L >>R >>d;
  int ans=0;
  rep_eq(i,L,R) {
    if (i%d==0) {
      ans++;
    }
  }
  cout <<ans <<endl;
  return 0;
}
