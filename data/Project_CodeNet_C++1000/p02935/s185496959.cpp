#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  vector<double> v(N);
  rep(i,0,N) cin >>v[i];

  sort(v.begin(),v.end());
  double ans=v[0];
  rep(i,1,N) ans=(ans+v[i])/2;
  cout <<ans <<endl;
  return 0;
}
