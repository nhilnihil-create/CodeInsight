#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll X, K, D;
  cin >> X >> K >> D;
  
  X = abs(X);
  if (X/D >= K){
    cout << X - K * D << endl;
    return 0;
  }
  ll cnt = X/D;//最短回数
  K -= cnt;
  X %= D;
  if (K%2 == 0)
    cout << X << endl;
  else
    cout << abs(X - D) << endl;
}
