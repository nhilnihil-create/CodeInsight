#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
*/#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")    
using namespace std;
/*namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<1024>>;
*/#define lli long long int
#define uli unsigned long long int
#define INF 999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(50) << S << endl
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
  cin >> N >> K;
  Vec(P,lli,N,0);
  Vec(Q,lli,N,0);
  rep(i,0,N) cin >> P[i];
  rep(i,0,N) cin >> Q[i];
  Sort(P);
  Sort(Q);Rev(Q);
  lli ok=1+pow(10,12);
  lli ng=-1;
  while(ok-ng>1){
      lli mid=(ok+ng)/2;
      num=0;
      rep(i,0,N)if(P[i]*Q[i]-mid>=0)num+=ceil((long double)(P[i]*Q[i]-mid)/Q[i]);
      if(num>K)ng=mid;
      else ok=mid;
  }
  Out(ok);
}