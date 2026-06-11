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
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int sen[10][10000];

main(){
  int c,r;
  while(cin>>r>>c,c|r){
    int ans=0;
    rep(i,r)rep(j,c)cin>>sen[i][j],ans+=sen[i][j];

    rep(i,1<<r){
      int tomote=0;
      rep(j,c){
        int romote=0;
        rep(k,r){
          if(sen[k][j]+(i>>k&1)&1)++romote;
          //cout<<(sen[k][j]^(i>>k&1))<<" ";
        }
        //cout<<endl;
        tomote+=max(romote,r-romote);
      }
      //cout<<tomote<<" "<<i<<endl;
      ans=max(ans,tomote);
    }
    cout<<ans<<endl;
  }
}