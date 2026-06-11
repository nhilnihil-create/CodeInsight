#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, K;
  cin>>N>>K;
  int A[N];
  for(int i=0;i<N;++i) {
    cin>>A[i];
  }
  int F[N], B[N];
  for(int i=0;i<N;++i) {
    F[i] = 0;
    B[i] = 0;
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      if(A[i]>A[j]) {
        if(j<i) F[i]++;
        else B[i]++;
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    ans += (K-1)*K/2%mod*F[i];
    ans %= mod;
    ans += K*(K+1)/2%mod*B[i];
    ans %= mod;
  }
  cout<<ans<<endl;
}

