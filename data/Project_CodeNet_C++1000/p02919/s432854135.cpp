#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <time.h>
#define ll long long
#define double long double
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
bool CAN=true;
using namespace std;

int main(){
  ll N,ans=0;
  cin>>N;
  ll P[N+1],POS[N+1];
  for(int i=1; i<=N; ++i){
    cin>>P[i];
    POS[P[i]]=i;
  }
  
  multiset<ll> S={0,0,N+1,N+1};
  
  for(int i=N; i>=1; --i){
    auto itr1=S.lower_bound(POS[i]);
    auto itr2=S.lower_bound(POS[i]);
    ll R1=*itr1,R2,L1,L2;
    itr1++;
    R2=*itr1;
    itr2--;
    L1=*itr2;
    itr2--;
    L2=*itr2;
    
    if(i<N) ans+=i*((L1-L2)*(R1-POS[i])+(R2-R1)*(POS[i]-L1));
    S.insert(POS[i]);
  }
  
  cout<<ans<<endl;
  return 0;
}