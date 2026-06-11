#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<int> a(N);
  rep(i,1,N) {
    int b; cin >>b;
    a[b-1]++;
  }
  rep(i,0,N) {
    cout <<a[i] <<endl;
  }
  return 0;
}
