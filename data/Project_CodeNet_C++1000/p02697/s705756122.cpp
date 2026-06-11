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
  int N, M;
  cin>>N>>M;
  pair<int, int> ans[M];
  int a=1, b=N;
  map<int, int> amap;
  for(int i=0;i<M;++i) {
    ans[i] = mp(a, b);
    amap[b-a]++;
    amap[N-(b-a)]++;
    a++;
    b--;
    while(amap[b-a]>0 || b-a==N-(b-a)) {
      b--;
    }
  }
  for(int i=0;i<M;++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
}
