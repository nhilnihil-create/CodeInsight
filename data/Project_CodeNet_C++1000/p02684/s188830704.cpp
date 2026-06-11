#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, K; cin >> N >> K;
  vector<ll> A(N+10, 0), seen(N+10, 0);
  rep(i, N) cin >> A[i+1];
  ll i = 1;
  while (seen[i] < 2 && K){
    seen[i]++;
    K--;
    i = A[i];
  }
  ll count = 0;
  rep(i, N+1){
    if (seen[i] == 2)
      count++;
  }
  if (count > 0)
    K %= count;
  while (K){
    K--;
    i = A[i];
  }
  cout << i << endl;
}
