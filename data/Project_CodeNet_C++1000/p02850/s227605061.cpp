#include <bits/stdc++.h>
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(25) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,H,W,M,K,L,R,N,num=0,sum=0,flag=0;string S,T;
  cin >> N;
  DV(G,int,N,0,0);
  map<pint,int>Cl;
  Vec(seen,bool,N,0);
  Vec(Eg,pint,N-1,pint(0,0));
  rep(i,0,N-1){
    cin >> A >> B;
    G[A-1].pb(B-1);
    G[B-1].pb(A-1);
    Eg[i]=pint(A-1,B-1);
  }
  rep(i,0,N)chmax(num,G[i].size());
  DV(ube,bool,N,num,0);
  queue<int>que;  
  que.push(0);
  seen[0]=true;
  while(!que.empty()){
    auto v=que.front();que.pop();
    for(auto nv:G[v]){
      if(seen[nv])continue;
      seen[nv]=true;
      rep(i,0,num)if(!ube[v][i]){
        Cl[pint(v,nv)]=i+1;
        ube[v][i]=true;
        ube[nv][i]=true;
        break;
      }
      que.push(nv);
    }
  }
  Out(num);
  for(auto v:Eg)Out(Cl[v]);
}


