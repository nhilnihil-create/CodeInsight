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

ll mypow(ll a, ll b) {
  ll ans = 1;
  ll two;
  ll tmp;
  while(b>0) {
    two = 1;
    tmp = a;
    while(2*two<b) {
      tmp *= tmp;
      tmp %= mod1;
      two *= 2;
    }
    b -= two;
    ans *= tmp;
    ans %= mod1;
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  int D[N];
  int maxnum = 0;
  map<int, ll> amap;
  for(int i=0;i<N;++i) {
    cin>>D[i];
    amap[D[i]]++;
    maxnum = max(maxnum, D[i]);
  }
  if(D[0]!=0) {
    cout<<0<<endl;
    return 0;
  }
  int zeronum = 0;
  for(int i=0;i<N;++i) {
    if(D[i]==0) zeronum++;
  }
  if(zeronum!=1) {
    cout<<0<<endl;
    return 0;
  }
  ll ans = 1;
  for(int i=2;i<=maxnum;++i) {
    ans *= mypow(amap[i-1], amap[i]);
    ans %= mod1;
  }
  cout<<ans<<endl;
}

