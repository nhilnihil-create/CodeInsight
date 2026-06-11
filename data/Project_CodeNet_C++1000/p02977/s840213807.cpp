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
  ll N;
  cin>>N;
  bool CAN=true;
  if(N==1) CAN=false;
  
  ll RUI[20],it=1;
  RUI[0]=1;
  RREP(i,20){
    RUI[i]=RUI[i-1]*2;
    if(RUI[i]==N) CAN=false;
    if(RUI[i-1]-1<=N && N<RUI[i]-1) it=i-1;
  }
  
  if(CAN){
    COYe;
    
    for(int i=1; i<RUI[it]-1; ++i){
      cout<<i<<" "<<i+1<<endl;
      cout<<i+N<<" "<<i+N+1<<endl;
    }
    cout<<RUI[it]-1<<" "<<N+1<<endl;
    
    for(int i=RUI[it]; i<=N; ++i){
      if(i%2==1){
        cout<<i-1<<" "<<i<<endl;
        cout<<i<<" "<<1<<endl;
        cout<<1<<" "<<N+i-1<<endl;
        cout<<N+i-1<<" "<<N+i<<endl;
      }
    }
    
    if(N%2==0){
      ll M=N-RUI[it],L=0,P=0;
      bool START=false;
      for(int i=20; i>=0; --i){
        if(START==true){
          if(M>=RUI[i]){
            M-=RUI[i];
          }
          else{
            L+=RUI[i];
          }
        }
        if(M>=RUI[i] && START==false){
          START=true;
          M-=RUI[i];
          P=i;
        }
      }
      
      cout<<N<<" "<<RUI[it]+L<<endl;
      cout<<RUI[P+1]-2<<" "<<2*N<<endl;
    }
  }
  else CONo;
  return 0;
}