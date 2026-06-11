#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define vector_rsort(x) sort(all(x));reverse(all(x))
#define array_rsort(x,n) sort(x,x+n);reverse(x,x+n);
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))

#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;
/*---------------------------------------------------*/

int n,u,k,v;
int g[105][105];

void init(){
  rep(i,105){
    rep(j,105){
      g[i][j]=INF;
    }
  }
}

void wf(){
  rep(k,105){
    rep(i,105){
      rep(j,105){
	g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
}

int main(){
  init();
  cin>>n;
  rep(i,n){
    cin>>u>>k;
    rep(i,k){
      cin>>v;
      g[u][v]=1;
    }
  }
  wf();
  cout<<1<<" "<<0<<endl;
  for(int i=2;i<=n;i++){
    if(g[1][i]==INF)cout<<i<<" "<<-1<<endl;
    else cout<<i<<" "<<g[1][i]<<endl;
  }
  return 0;
}