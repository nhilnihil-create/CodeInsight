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
using Edge=pair<int,int>;
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
  ll N,K,ans=1;
  cin>>N>>K;
  ll A[N],S=0;
  REP(i,N){
    cin>>A[i];
    S+=A[i];
  }
  
  for(ll i=1; i<=sqrt(S); ++i){
    if(S%i==0){
      ll T=S/i,SUM[N+1],cnt=0;
      SUM[0]=0;
      vector<ll> B;
      REP(j,N){
        if(A[j]%T!=0) B.PB(A[j]%T);
      }
      SORT(B);
      RREP(j,B.size()) SUM[j]=SUM[j-1]+B[j-1];
      
      RREP(j,B.size()){
        if(SUM[j-1]==(B.size()-j+1)*T-(SUM[B.size()]-SUM[j-1])){
          if(K>=SUM[j-1]) chmax(ans,T);
        }
      }
      
      T=i,cnt=0;
      SUM[0]=0;
      vector<ll> C;
      REP(j,N){
        if(A[j]%T!=0) C.PB(A[j]%T);
      }
      SORT(C);
      RREP(j,C.size()) SUM[j]=SUM[j-1]+C[j-1];
      
      RREP(j,C.size()){
        if(SUM[j-1]==(C.size()-j+1)*T-(SUM[C.size()]-SUM[j-1])){
          if(K>=SUM[j-1]) chmax(ans,T);
        }
      }
    }
  }
  
  co(ans);
  return 0;
}