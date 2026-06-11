#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  vector<vector<pair<int, int> > > edge(N);
  int A;
  int x, y;
  for(int i=0;i<N;++i){
    cin>>A;
    for(int j=0;j<A;++j){
      cin>>x>>y;
      x--;
      edge[i].push_back(mp(x, y));
    }
  }
  bool ok;
  int ans = 0;
  int tmp;
  for(int bit=0;bit<(1<<N);++bit){
    map<int, int> amap;
    tmp = 0;
    for(int i=0;i<N;++i){
      if((bit&(1<<i))!=0){
        amap[i] = 1;
        tmp++;
      }
    }
    ok = true;
    for(int i=0;i<N;++i){
      if(amap[i]==1){
        for(int j=0;j<edge[i].size();++j){
          if(amap[edge[i][j].fi] != edge[i][j].se){
            ok = false;
          }
        }
      }
    }
    if(ok) {
      ans = max(ans, tmp);
    }
  }
  cout<<ans<<endl;
}

