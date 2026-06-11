#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  int ans=0;
  if (N%1000!=0) ans=1000-N%1000;
  cout <<ans <<endl;
  return 0;
}
