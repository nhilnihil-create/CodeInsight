#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
using namespace std;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
  int H,W;
  cin>>H>>W;
  int DP[H+1][W+1];
  char S[H+1][W+1];
  REP(i,H+1){
    REP(j,W+1){
      DP[i][j]=MAX;
      if(0<i && 0<j) cin>>S[i][j];
      else S[i][j]='?';
    }
  }
  
  if(S[1][1]=='#') DP[1][1]=1;
  else DP[1][1]=0;
  
  for(int i=1; i<=H; ++i){
    for(int j=1; j<=W; ++j){
      if(S[i-1][j]=='#' && S[i][j]=='#') chmin(DP[i][j],DP[i-1][j]);
      else if(S[i-1][j]=='#' && S[i][j]=='.') chmin(DP[i][j],DP[i-1][j]);
      else if(S[i-1][j]=='.' && S[i][j]=='#') chmin(DP[i][j],DP[i-1][j]+1);
      else if(S[i-1][j]=='.' && S[i][j]=='.') chmin(DP[i][j],DP[i-1][j]);
      else chmin(DP[i][j],DP[i][j]);
      
      if(S[i][j-1]=='#' && S[i][j]=='#') chmin(DP[i][j],DP[i][j-1]);
      else if(S[i][j-1]=='#' && S[i][j]=='.') chmin(DP[i][j],DP[i][j-1]);
      else if(S[i][j-1]=='.' && S[i][j]=='#') chmin(DP[i][j],DP[i][j-1]+1);
      else if(S[i][j-1]=='.' && S[i][j]=='.') chmin(DP[i][j],DP[i][j-1]);
      else chmin(DP[i][j],DP[i][j]);
    }
  }
  
  co(DP[H][W]);
  return 0;
}