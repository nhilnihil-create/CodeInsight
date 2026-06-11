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

int main() {
  int N;
  cin>>N;
  vector<ll> A(N);
  ll maxnum=-big, minnum=big;
  for(int i=0;i<N;++i) {
    cin>>A[i];
  }
  sort(A.begin(), A.end());
  maxnum = A[N-1];
  minnum = A[0];
  ll ans1 = minnum, ans2 = maxnum;
  for(int i=1;i<N-1;++i) {
    if(A[i]>=0) {
      ans1 = ans1 - A[i];
    }
    else {
      ans2 = ans2 - A[i];
    }
  }
  ll ans = ans2 - ans1;
  cout<<ans<<endl;
  ans1 = minnum;
  ans2 = maxnum;
  for(int i=1;i<N-1;++i) {
    if(A[i]>=0) {
      cout<<ans1<<" "<<A[i]<<endl;
      ans1 -= A[i];
    }
    else {
      cout<<ans2<<" "<<A[i]<<endl;
      ans2 -= A[i];
    }
  }
  cout<<ans2<<" "<<ans1<<endl;
}

