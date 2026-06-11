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
  
  ll o=1e18;
  ll N; cin>>N;
  ll ans = 1;
  vector<ll> A(N, 0);
  rep(i, N){
    cin>>A[i];
    if (A[i] == 0){
      cout<<0<<endl;
      return 0;
    }
  }
  double check = 0;
  rep(i, N){
    ans *= A[i];
    check += (double)log10(A[i]);
    if (ans > 1000000000000000000 || ans < 0 || check > 18.00000000){
      cout << -1 << endl;
      return 0;
    }
  }
  cout <<ans << endl;
}
