#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
//gcd(x, y) -> xとyの最大公約数
ll gcd(ll x, ll y){
    return y ? gcd(y, x % y) : x;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll N, M; cin >> N >> M;
   vector<ll> A(N);
   rep(i,N) cin >> A[i];
   ll lca = A[0];
   for (int i=1; i < N; ++i){
      lca /= gcd(lca, A[i]);
      lca *= A[i];
      if (lca > 2 * M) break;
   }
   int div2 = 1;
   while(A[0]%2 == 0){
      div2 <<= 1;
      A[0]/=2;
   }
   for (int i=1; i < N; ++i){
      if (!((A[i]%div2==0) && (A[i]%(div2<<1)!=0))){
         cout << 0 << endl;
         return 0;
      }
   }
   cout << ((M+lca/2)/lca) << endl;
}