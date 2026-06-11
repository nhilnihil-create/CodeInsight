#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 9999999999
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
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N >> M;
  DV(dp,lli,1010,(1<<N)+10,INF);//dp[i][j]:=i個目の鍵まで見たとき，箱{集合j}が開いているような鍵の買い方の値段の最小値
  Vec(key,pint,M,pint(0,0));//値段,その鍵で開く箱の集合
  rep(i,0,M){
    cin >> key[i].first >> A;
    while(A--){
      cin >> B;
      B--;
      key[i].second+=(1<<B);
    }
  }
  dp[0][0]=0;
  rep(i,0,M)rep(j,0,1<<N){
    if(i>0)chmin(dp[i][j],dp[i-1][j]);
    chmin(dp[i][j|key[i].second],dp[i][j]+key[i].first);//j|key[i].second 集合jと集合key[i].secondの和集合
  }
  if(dp[M-1][(1<<N)-1]==INF)Out(-1);
  else Out(dp[M-1][(1<<N)-1]);
}
