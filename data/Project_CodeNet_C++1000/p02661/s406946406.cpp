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

10 - 10000
9991個
真ん中取ればいい

3 - 5
3,4,5=3個

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N; cin >> N;
  vector<ll> A(N, 0), B(N, 0);
  ll a = 0, b = 0, ans = 0;
  rep(i, N) cin >> A[i] >> B[i];
  sort(all(A));
  sort(all(B));
  ll mid = N/2;
  if (N%2 == 0){
    a += A[mid] + A[mid - 1];
    b += B[mid] + B[mid - 1];
    ans = b - a + 1;
  }
  else
    ans = B[mid] - A[mid] + 1;
  cout <<ans << endl;
}
