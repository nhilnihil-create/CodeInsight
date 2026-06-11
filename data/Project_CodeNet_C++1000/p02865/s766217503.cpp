#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  int ans=0;
  rep(i,1,(N+1)/2) {
    int j=N-i;
    if (i!=j) {
      ans++;
    }
  }
  cout <<ans <<endl;
  return 0;
}
