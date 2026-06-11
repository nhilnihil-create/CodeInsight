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
  int A[N];
  for(int i=0;i<N;++i) {
    cin>>A[i];
    A[i]--;
  }
  map<int, int> amap;
  int now = 0;
  int dist, cycle, point;
  int ans=-1;
  for(int i=1;i<=K;++i) {
    if(amap[now]>0) {
      point = now;
      dist = amap[now]-1;
      cycle = i-dist-1;
      break;
    }
    amap[now] = i;
    now = A[now];
    if(i==K) ans = now;
  }
  if(ans>-1) {
    cout<<ans+1<<endl;
    return 0;
  }
  K -= dist;
  K %= cycle;
  now = point;
  for(int i=0;i<K;++i) {
    now = A[now];
  }
  ans = now;
  cout<<ans+1<<endl;
}

