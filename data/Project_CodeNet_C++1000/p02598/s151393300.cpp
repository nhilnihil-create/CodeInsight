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
  
  ll N, K;
  cin >> N >> K;
  
  vector<ll> A(N, 0);
  rep(i, N) cin >> A[i];
  ll high = 1e9, low = 1, mid = (high + low) / 2;
  while (high > low){
    ll cnt = 0;
    rep(i, N){
      ll a = A[i]-1;
      cnt += a / mid;
    }
    if (cnt > K)
      low = mid + 1;
    else
      high = mid;
    mid = (high + low) / 2;
//cout << "high:"<< high << "low:"<< low << "cnt:"<< cnt << endl;    
  }
  //check
  ll cnt = 0;
  rep(i, N){
    ll a = A[i]-1;
    cnt += a / low;
  }
  if (cnt > K)
    low++;
  cout << low << endl;
}
