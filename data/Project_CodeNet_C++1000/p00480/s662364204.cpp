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
static const double EPS = 1e-10;
typedef long long ll;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define PB push_back

ll dp[21][100];
int n;
int num[100];

main(){
  cin>>n;
  rep(i,n)cin>>num[i];
  
  dp[num[0]][0]=1;
  
  for(int i=1;i<n-1;i++){
    rep(j,21){
      int nn=j-num[i];
      if(nn>=0)dp[j][i]+=dp[nn][i-1];
      nn=j+num[i];
      if(nn<21)dp[j][i]+=dp[nn][i-1];
    }
  }
  cout<<dp[num[n-1]][n-2]<<endl;
}