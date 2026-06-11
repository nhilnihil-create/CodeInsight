#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int n,l;
  cin >> n >>l;
  int t = n*l + n*(n-1)/2;//n個のあじ
  if(0<=-l && -l <= n-1){
    cout << t << endl;
  }
  else if(l > 0){
    cout << t-l <<endl;
  }
  else{
    cout << t-(l+n-1) << endl;
  }
  return 0;
}