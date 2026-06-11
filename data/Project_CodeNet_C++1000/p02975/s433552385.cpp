#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N;
  Vec(P,lli,N,0);
  rep(i,0,N)cin >> P[i];
  map<int,int> mp;
  rep(i,0,N)mp[P[i]]++;
  if(mp.size()>3)flag=1;
  else if(mp.size()==3){for(auto v:mp)if(v.second!=N/3)flag=1;for(auto v:mp)sum^=v.first;if(sum)flag=1;}
  else if(mp.size()==2){if(mp[0]!=N/3||N%3!=0||mp.count(0)==0)flag=1;}
  else if(mp.size()==1)if(mp.count(0)==0)flag=1;
  if(flag)Out("No");
  else Out("Yes");
}