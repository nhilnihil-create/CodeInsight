#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int DP1[3005][3005], DP2[3005][3005]; // Tまでにたべきる

int main() {
  int N, T;
  cin>>N>>T;
  int A[N], B[N];
  for(int i=0;i<N;++i) cin>>A[i]>>B[i];
  for(int i=0;i<T;++i) {
    if(i>=A[0]) DP1[0][i] = B[0];
  }
  for(int i=1;i<N;++i) {
    for(int j=0;j<T;++j) {
      DP1[i][j] = DP1[i-1][j];
      if(j>=A[i]) DP1[i][j] = max(DP1[i][j], DP1[i-1][j-A[i]]+B[i]);
    }
  }
  for(int i=0;i<T;++i) {
    if(i>=A[N-1]) DP2[N-1][i] = B[N-1];
  }
  for(int i=N-2;i>=0;--i) {
    for(int j=0;j<T;++j) {
      DP2[i][j] = DP2[i+1][j];
      if(j>=A[i]) DP2[i][j] = max(DP2[i][j], DP2[i+1][j-A[i]]+B[i]);
    }
  }
  int ans = 0;
  ans = max(DP2[1][T-1]+B[0], DP1[N-2][T-1]+B[N-1]);
  for(int i=1;i<N-1;++i) {
    for(int j=0;j<T;++j) {
      ans = max(ans, DP1[i-1][j]+DP2[i+1][T-1-j]+B[i]);
    }
  }
  cout<<ans<<endl;
}

