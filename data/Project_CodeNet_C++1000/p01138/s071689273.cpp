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
#include <ctime>
#include <list>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
typedef pair<int,int> PI;
#ifndef M_PI
const double M_PI=acos(-1);
#endif
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int((a).size()))
#define F first
#define S second
int dx[]={0,1,0,-1,0,0},dy[]={1,0,-1,0,0,0};
int dz[]={0,0,0,0,1,-1};

int st[10000];
int ed[10000];
int n;

void solve(){
  priority_queue<PI> q;
  rep(i,n){
    int hh,mm,ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    st[i]=hh*3600+mm*60+ss;
    q.push(mp(-st[i],0));
    scanf("%d:%d:%d",&hh,&mm,&ss);
    ed[i]=hh*3600+mm*60+ss;
    q.push(mp(-ed[i],1));
  }
  int ans=0;
  int cu=0;
  while(!q.empty()){
    int cc=q.top().S;
    q.pop();
    cu+=cc;
    if(cc==0 && cu==0)++ans;
    else if(cc==0)--cu;
  }
  cout<<ans<<endl;
}


main(){
  while(cin>>n,n)
    solve();
}