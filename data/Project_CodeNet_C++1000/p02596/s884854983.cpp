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
  
  ll K; cin >> K;
  ll num = 7;
  rep(i, 1e6+1){
    if (num % K == 0){
      cout << i+1 << endl;
      return 0;
    }
    num *= 10;
    num += 7;
    num %= K;
  }
  cout << -1 << endl;
}
