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
  ll K, N;
  cin>>K>>N;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  ll dist = 0;
  for(int i=0;i<N;++i) {
    if(i<N-1) {
      dist = max(dist, A[i+1]-A[i]);
    }
    else {
      dist = max(dist, (K-A[N-1]+A[0]));
    }
  }
  cout<<K-dist<<endl;
}

