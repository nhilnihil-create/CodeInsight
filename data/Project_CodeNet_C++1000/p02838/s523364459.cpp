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

ll DP[61][300005];

int main() {
  int N;
  cin>>N;
  ll A[N];
  ll two;
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=0;i<N;++i) {
    two = 1;
    for(int bit=0;bit<61;++bit) {
      if((A[i]&two)!=0) DP[bit][i]++;
      two *= 2;
    }
  }
  for(int bit=0;bit<61;++bit) {
    for(int i=1;i<N;++i) {
      DP[bit][i] += DP[bit][i-1];
    }
  }
  /**
  for(int bit=0;bit<61;++bit) {
    for(int i=0;i<N;++i) {
      cout<<DP[bit][i]<<" ";
    }
    cout<<endl;
  }
  **/
  ll ans = 0;
  for(int i=0;i<N;++i) {
    two = 1;
    for(int bit=0;bit<61;++bit) {
      if((A[i]&two)!=0) {
        ans += (two%mod)*(N-1-i-(DP[bit][N-1]-DP[bit][i]))%mod;
        ans %= mod;
      }
      else {
        ans += (two%mod)*(DP[bit][N-1]-DP[bit][i])%mod;
        ans %= mod;
      }
      two *= 2;
    }
  }
  cout<<ans<<endl;
}

