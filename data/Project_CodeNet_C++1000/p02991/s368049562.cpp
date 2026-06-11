#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,pi> plpi;
typedef vector<int> vi;
typedef set<int> si;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N,M;
int u[100010],v[100010];
int S,T;
vi g[100010];
ll d[100010][3];
void add_edge(int from,int to){
  g[from].push_back(to);
}
void rec(int i,int j,ll m){
  if(d[i][j]<=m) return ;
  d[i][j]=m;
  rep(k,g[i].size()){
    int t=g[i][k];
    rec(t,(j+1)%3,m+1);
  }
}
void dijkstra(int s){
  priority_queue<plpi,vector<plpi>,greater<plpi> > q;//pair(コスト、頂点)としてコストの小さい順に並ぶ
  d[s][0]=0;
  q.push(mp(0,mp(s,0)));
  while(!q.empty()){
    plpi p = q.top();q.pop();
    pi w=p.second;//最新の確定した頂点
    int x=w.first,y=w.second;
    if(d[x][y]<p.first) continue;//取り出した頂点のコストが最短コストより長かったら破棄
    for(int i=0;i<g[x].size();i++){//取り出した頂点と隣接した頂点を調べる
      int t=g[x][i];
      if(d[t][(y+1)%3]>d[x][y]+1){//頂点tまでの暫定最短距離よりwまでの最短距離+w→tのコストが小さければ更新
	d[t][(y+1)%3]=d[x][y]+1;
	q.push(mp(d[t][(y+1)%3],mp(t,(y+1)%3)));
      }
     }
  }
}



int main(){
  cin>>N>>M;
  rep(i,M){
    cin>>u[i]>>v[i];
    u[i]--;v[i]--;
  }
  cin>>S>>T;
  S--;T--;
  rep(i,M) add_edge(u[i],v[i]);
  rep(i,N){
    rep(j,3){
      d[i][j]=INFLL;
    }
  }
  dijkstra(S);
  prin((d[T][0]!=INFLL?d[T][0]/3:-1));
  return 0;
}
