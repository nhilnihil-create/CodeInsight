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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  ll A[N+1], B[N];
  for(int i=0;i<=N;++i) cin>>A[i];
  for(int i=0;i<N;++i) cin>>B[i];
  ll ans = 0;
  ll zero = 0;
  for(int i=0;i<N;++i) {
    if(A[i]>=B[i]) {
      ans += B[i];
      A[i] -= B[i];
      B[i] = 0;
    }
    else {
      ans += A[i];
      B[i] -= A[i];
      A[i] = 0;
      ans += min(A[i+1], B[i]);
      A[i+1] = max(A[i+1]-B[i], zero);
    }
  }
  cout<<ans<<endl;
}

