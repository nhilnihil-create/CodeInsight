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
#include <list>
#include <fstream>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> vi;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define F first
#define S second


int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};



main(){
  int n,m,p;
  while(cin>>n>>m>>p,n|m|p){
    int sum=0,mt,t;
    rep(i,n){
      cin>>t;
      sum+=t;
      if(i+1==m)mt=t;
    }

    if(mt){
      printf("%d\n",(100-p)*sum/mt);
    }else cout<<0<<endl;
  }
}