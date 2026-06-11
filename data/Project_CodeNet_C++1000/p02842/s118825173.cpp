#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  int temp=ceil(N/1.08);
  if ((int)(temp*1.08)==N) {
    cout <<temp <<endl;
  } else {
    cout <<":(" <<endl;
  }
  return 0;
}
