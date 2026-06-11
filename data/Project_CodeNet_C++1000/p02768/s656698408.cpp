#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

ll RepSq(ll a,ll n,ll mod){
  if(n==0){
    return 1;
  }else if(n%2!=0){
    return (a*RepSq(a,n-1,mod))%mod;
  }else{
    ll x=RepSq(a,n/2,mod);
    return (x*x)%mod;
  }
}

int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  ll mod=1000000007;
  ll comb[400000],inv[400000];
  comb[0]=1; inv[1]=1; comb[1]=n%mod;
  for(int i=2;i<300000+1;i++){
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    comb[i]=(comb[i-1]*(n+1-i))%mod;
    comb[i]=(comb[i]*inv[i])%mod;
  }
  cout<<(3*mod+RepSq(2,n,mod)-1-comb[a]-comb[b])%mod;
}
