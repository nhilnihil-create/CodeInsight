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
  ll N, K;
  cin>>N>>K;
  vector<ll> A(N), F(N);
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=0;i<N;++i) cin>>F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll l=0, r=big, m;
  ll cost;
  while(l<r) {
    m = (l+r)/2;
    cost = 0;
    for(int i=0;i<N;++i) {
      if(A[i]*F[i]<=m) continue;
      cost += A[i]-m/F[i];
    }
    if(cost>K) l=m+1;
    else r=m;
  }
  cout<<l<<endl;
}

