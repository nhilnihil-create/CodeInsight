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

ll DP[100005];

int main() {
  int N, M;
  cin>>N>>M;
  int tmp;
  map<int, int> amap;
  for(int i=0;i<M;++i) {
    cin>>tmp;
    amap[tmp]++;
  }
  DP[0] = 1;
  for(int i=1;i<=N;++i) {
    if(amap[i]>0) continue;
    if(i==1) DP[i] = DP[i-1]%mod;
    else DP[i] = (DP[i-1]+DP[i-2])%mod;
  }
  cout<<DP[N]<<endl;
}

