#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

ll gcd(ll x,ll y){
  if(x%y==0) return y;
  
  return gcd(y,x%y);
}

ll lcm(ll x,ll y){
  return x*y/gcd(x,y);
}

int main(void){
  ll a,b; cin >> a >> b;

  cout << lcm(a,b) << endl;
  
  return 0;
}
