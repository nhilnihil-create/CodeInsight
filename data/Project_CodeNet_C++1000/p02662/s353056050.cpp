#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;
#define pai 3.141592653589793238462643383279

int modpow(ll a, ll n, ll p){
	if(n==0) return 1;
	if(n%2) return (a*modpow(a, n-1, p))%p;
	if(!(n%2)){
		ll t=modpow(a, n/2, p);
		return (t*t)%p;
	}
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int N, S; cin >> N >> S; ll A[N];
    rep(i, N){
        cin >> A[i];
    }
   ll res = 0; ll dp[3010][3010] = {};
   dp[0][0] = 1;
   rep(i, N){
       rep(j, S+1){
           dp[i+1][j]+=dp[i][j];
           dp[i+1][j]%=mod;
       }
       if(A[i]<=S){
         dp[i+1][A[i]] += modpow(2, N-1, mod);
         dp[i+1][A[i]]%=mod;
       }
       for(int j=1; j<=S; ++j){
          if(A[i]+j<=S){
            dp[i+1][j+A[i]]+=dp[i][j]*modinv(2, mod);
            dp[i+1][j+A[i]]%=mod;
          } 
       }
   }
  cout << dp[N][S] << endl;
}