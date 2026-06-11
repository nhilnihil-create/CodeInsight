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
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int x[200],y[200];

main(){
  int n;
  while(cin>>n,n){
    int maxx=0,maxy=0,minx=0,miny=0;
    x[0]=y[0]=0;
    rep(i,n-1){
      int ni,di;
      cin>>ni>>di;
      switch(di){
      case 0:
        x[i+1]=x[ni]-1;
        y[i+1]=y[ni];
        break;
      case 1:
        x[i+1]=x[ni];
        y[i+1]=y[ni]-1;
        break;
      case 2:
        x[i+1]=x[ni]+1;
        y[i+1]=y[ni];
        break;
      case 3:
        x[i+1]=x[ni];
        y[i+1]=y[ni]+1;
        break;
      }
      minx=min(minx,x[i+1]);
      miny=min(miny,y[i+1]);
      maxx=max(maxx,x[i+1]);
      maxy=max(maxy,y[i+1]);
    }
    cout<<(maxx-minx+1)<<' '<<(maxy-miny+1)<<endl;
  }
}