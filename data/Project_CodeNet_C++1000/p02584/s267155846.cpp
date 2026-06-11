#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll X,k,d; cin >> X >> k >> d;
  X = abs(X);

  ll num = min(k,X/d);
  
  ll x = X-num*d;
  k -= num;

  x = k%2==0 ? x:abs(x-d);

  cout << x << endl;
  
  return 0;
}
