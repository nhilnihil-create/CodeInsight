#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(i = 0; i < n; i++)
//2D::rep(i,j)rep(j,j)cin>>bin[i][j];
//vector<int> a(n)
#define A1 cout<<"No"<<endl
#define A2 cout<<"Yes"<<endl
#define A3 cout<<ans<<endl
#define AA(i) cout<<i<<endl
const int U=2e5+5;
const ll MOD=1000000007;
const int INF = 1001001001;
#define size 200010

ll POW(ll n,ll m){
  long long pow = 1;
  while (m>0) {
    if ((m&1) == 1) pow = (pow*n)%MOD;
    m >>= 1;
    n = (n*n)%MOD;
  }
    return pow;
}

int main(){
  int N,K; cin >> N >> K;
  int n;
  ll ans = 0;
  map<int,ll> A;
  for(int i=1;i<=K;i++){
    int t = K-i+1;
    n = K / t;
    A[t] += POW(n,N);
    for(int j=2;;j++){
      if(j * t > K) break;
      else{
        A[t] -= A[j * t];
        A[t] = (A[t] + MOD) % MOD;
      }
    }
  }
  for(int i=1;i<=K;i++){
    ans = (ans + i * A[i] % MOD + MOD) % MOD;
  }
  AA(ans);
  return 0;
}