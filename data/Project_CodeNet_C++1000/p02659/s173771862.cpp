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
  
  ll A; cin>>A;
  string S; cin>>S;
  ll B=0;
  ll c=1;
  int i=0;
  bool deci = false;
  while(S[i]){
    if (S[i] >= '0' && S[i] <= '9')
      B = B * 10 + S[i] - '0';
    if (deci)
      c *= 10;
    if (S[i] == '.')
      deci = true;
    i++;
  }
  ll ans = A * B / c;
  cout << ans << endl;
}
