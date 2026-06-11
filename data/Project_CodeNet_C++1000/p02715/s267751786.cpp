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
vector<lli> divisor(lli N){
  vector<lli>res;
  for(lli i=1;i*i<=N;i++){
    if(N%i==0){
      res.push_back(i);
      if(i!=N/i)res.push_back(N/i);
    }
  }
  Sort(res);
  return res;
}
lli modpow(lli n,lli k,lli m){
  if(k==0)return 1;
  else if(k%2==1)return modpow(n,k-1,m)*n%m;
  else{
    lli temp=modpow(n,k/2,m);
    return temp*temp%m;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N >> K;
  Vec(dp,lli,K,0);//dp[i]:=gcd{A_i}=i+1となる場合の数mod1e9+7
  rrep(i,K,0){
    num=K/(i+1);
    dp[i]+=modpow(num,N,mod);
    dp[i]=(dp[i]+mod)%mod;
    for(auto v:divisor(i+1)){
      if(v!=i+1)dp[v-1]-=dp[i];
      dp[v-1]=(dp[v-1]+mod)%mod;
    }
    sum+=dp[i]*(i+1);
    sum%=mod;
  }
  Out(sum);
}
