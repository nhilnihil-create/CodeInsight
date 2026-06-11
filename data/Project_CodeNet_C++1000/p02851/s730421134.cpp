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
using Edge=pair<ll,ll>;
using Graph=vector<vector<Edge>>;
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
  ll N,K,ans=0;
  cin>>N>>K;
  ll A[N],S[N+1],T[N+1];
  S[0]=0;
  T[0]=0;
  REP(i,N){
    cin>>A[i];
    S[i+1]=S[i]+A[i];
    T[i+1]=(S[i+1]-i-1)%K;
    if(T[i+1]<0) T[i+1]+=K;
  }
  
  vector<pair<ll,ll>> L;
  REP(i,N+1) L.PB(MP(T[i],i));
  SORT(L);
  
  ll cnt=0,NT[N+1];
  NT[0]=0;
  RREP(i,N){
    if(L[i].first>L[i-1].first) cnt++;
    NT[L[i].second]=cnt;
  }
  
  ll COUNT[N+1];
  REP(i,N+1) COUNT[i]=0;
  COUNT[0]=1;
  
  if(N<K){
    for(ll i=1; i<=N; ++i){
      ans+=COUNT[NT[i]];
      COUNT[NT[i]]++;
    }
  }
  else{
    for(ll i=1; i<=K-1; ++i){
      ans+=COUNT[NT[i]];
      COUNT[NT[i]]++;
    }
    for(ll i=K; i<=N; ++i){
      COUNT[NT[i-K]]--;
      ans+=COUNT[NT[i]];
      COUNT[NT[i]]++;
    }
  }
  
  co(ans);
  return 0;
}