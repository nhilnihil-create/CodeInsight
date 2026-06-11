#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  ll A,V,B,W,T; cin >>A >>V >>B >>W >>T;
  ll x=abs(A-B);
  ll y=(V-W)*T;
  cout <<(x<=y ? "YES":"NO") <<endl;
  return 0;
}
