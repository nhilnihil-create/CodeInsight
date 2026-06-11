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
#define mt make_tuple
#define pqueue priority_queue
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
  ll tmp;
  while(l<r) {
    m = (l+r)/2;
    tmp = 0;
    for(int i=0;i<N;++i) {
      if(A[i]*F[i]<=m) continue;
      if((A[i]*F[i]-m)%F[i]==0) tmp += (A[i]*F[i]-m)/F[i];
      else tmp += (A[i]*F[i]-m)/F[i]+1;
    }
    if(tmp>K) l = m+1;
    else r = m;
  }
  cout<<l<<endl;
}

