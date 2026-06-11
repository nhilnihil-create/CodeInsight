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
#include <ctime>
#include <numeric>
#include <fstream>
#include <valarray>
using namespace std;
static const double EPS = 1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
const long double pi=acos(-1.0);
int dx[]={0,1,0,-1,1,1,-1,-1,0},dy[]={1,0,-1,0,1,-1,1,-1,0};

ll dp[31];

main(){
  dp[0]=1;

  for(int i=1;i<=30;++i)
    for(int j=max(0,i-3);j<i;++j)
      dp[i]+=dp[j];
  int n;
  while(cin>>n,n)cout<<(dp[n]+3649)/3650<<endl;
}