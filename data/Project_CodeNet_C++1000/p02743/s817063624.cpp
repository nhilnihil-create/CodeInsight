#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  if(c-a-b > 0 && 4*a*b < (c-a-b)*(c-a-b)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}