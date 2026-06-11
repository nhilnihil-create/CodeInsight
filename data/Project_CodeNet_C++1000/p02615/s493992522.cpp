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
4
2 2 1 3

3 2 2 1
0 3 2 2

123456

6 5 4 3 2 1
0 6 5 4 5 4

12345
5 4 3 2 1
0 5 4 4 3

5=0112
6=01122
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, ans = 0; cin >> N;
  vector<ll> A(N, 0);
  rep(i, N) cin >> A[i];
  sort(all(A));
  reverse(all(A));
  ll end = N/2;
  if(N%2)
    end++;
  rep(i, end)
    ans += A[i]*2;
  ans -= A[0];
  if (N%2)
    ans -=A[end-1];
  cout << ans << endl;
           
}
