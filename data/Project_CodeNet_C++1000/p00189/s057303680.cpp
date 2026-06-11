#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define PB push_back

ll cost[10][10];
ll n,m;


void wf(){
  rep(k,m){
    rep(i,m){
      rep(j,m)cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    }
  }
}

main(){
  while(cin>>n,n){
    m=0;
    rep(i,10){
      rep(j,10){
        cost[i][j]=1<<20;
      }
      cost[i][i]=0;
    }

    rep(i,n){
      ll a,b,c;
      cin>>a>>b>>c;
      m=max(m,max(a,b));
      cost[a][b]=c;
      cost[b][a]=c;
    }
    ++m;
    wf();
    ll minan=2<<20,town;

    rep(i,m){
      ll sum=0;
      rep(j,m)sum+=cost[i][j];
      if(sum<minan){
        minan=sum;
        town=i;
      }
    }
    cout<<town<<" "<<minan<<endl;
  }
}