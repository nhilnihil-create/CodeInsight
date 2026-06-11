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

////////// 繰り返し二乗法 //////////

ll power(ll a,ll b){
  ll res=1;
  while(b>0){
    if(b&1) res=res*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return res;
}

//////////////////////////////////////////////////

int main(){
  ll N,ans=0;
  cin>>N;
  bool CAN=true; //全て偶数かどうか
  int A[N];
  char B[N];
  REP(i,N){
    cin>>B[i];
    A[i]=B[i]-'0'-1;
    if(A[i]%2!=0) CAN=false;
  }
  
  if(CAN){
    REP(i,N) A[i]/=2;
  }
  else{
    REP(i,N){
      if(A[i]==2) A[i]=0;
    }
  }
  
  ///////
  
  vector<ll> L;
  REP(i,N){
    L.PB(A[i]);
  }
  
  while(L.size()>1){
    vector<ll> LL;
    ll T=-1,S=L.size(),P=0LL;
    while(S>0){
      S/=2;
      T++;
    }
    REP(i,power(2,T)) P^=L[i];
    LL.PB(P);
    
    for(ll i=power(2,T); i<L.size(); ++i){
      P^=L[i];
      P^=L[i-power(2,T)];
      LL.PB(P);
    }
    L=LL;
  }
  
  ans=L[0];
  
  ///////
  
  if(CAN) ans*=2;
  co(ans);
  return 0;
}