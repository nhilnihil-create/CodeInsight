#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
#include<bitset>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define pb(b) push_back(b) 
#define all(a) a.begin(),a.end()
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define llpvec vector<pair<ll,ll>>
#define size_(a,b) (a,vector<ll>(b))
#define S 21
/* 
UnionFind：素集合系管理の構造体
issame(x,y): x と y が同じ集合にいるか
treesize(x): x を含む集合の要素数
weight(x): xでの重みの累積和
diff(x,y): x,yの重みの差
unite(x,y): wの重みを考慮しx と y を同じ集合にする
*/
template<class Abel> struct UnionFind{
 vector<ll>par;
 vector<ll>rank;
 vector<Abel>diff_weight;
 UnionFind(ll n=1,Abel SUM_UNITY=0) {
  init(n,SUM_UNITY);
  }
 void init(ll n=1,Abel SUM_UNITY=0){
  par.resize(n);rank.resize(n);diff_weight.resize(n);
  for (ll i=0;i<n;++i)par[i]=i,rank[i]=0,diff_weight[i]=SUM_UNITY; 
 }
 ll root(ll x){
  if(par[x]==x)return x;
  else {
   ll r=root(par[x]);
   diff_weight[x]+=diff_weight[par[x]];
   return par[x]=r;
  }
 }
 Abel weight(ll x){
  root(x);
  return diff_weight[x];
 }
 bool issame(ll x,ll y) {
  return root(x)==root(y);
 }
 bool unite(ll x,ll y,Abel w) {
  w+=weight(x);w-=weight(y);
  x=root(x);y=root(y);
  if(x==y)return false;
  if(rank[x]<rank[y])swap(x,y),w=-w;
  if(rank[x]==rank[y])++rank[x];
   par[y]=x;
   diff_weight[y]=w;
   return true;
  }
 ll treecnt(ll n){
  map<ll,bool>used;
  ll ans=0,i;
  rep(i,0,n){
   ll p=root(par[i]);
   if(used[p])continue;
   used[p]=true;
   ans++;
  }
  return ans;
 }
 Abel diff(ll x, ll y){return weight(y)-weight(x);}
};
/*mod*/const int mod=1e9+7;
/*pi*/const double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗 1*/ll llpow(ll x,ll n){ll ans=1,ii;rep(ii,0,n){ans*=x;}return ans;}
/*n乗 2*/ll modpow(ll x,ll n){ll ans=x,ii,tmp=x,t1=1;ii=1; while(ii<n){if(ii*2<n){ans*=ans;ans%=mod;ii*=2;}else{t1=1;tmp=x;while(t1*2<n-ii){tmp*=tmp;tmp%=mod;t1*=2;}ans*=tmp;ans%=mod;ii+=t1;}}return ans;}
/*階乗*/ll fact(ll x){ll ii,ans=1;rep(ii,0,x){ans*=(x-ii);ans%=mod;}return ans;}
/*逆元*/ll inv(ll x){return modpow(x,mod-2);}
/*nCr*/ll ncr(ll n,ll r){ll a=fact(n),b=inv(fact(n-r)),c=inv(fact(r));if(n-r<0)return 0;else return (((a*b)%mod)*c)%mod;}
/*nPr*/ll npr(ll n,ll r){ll a=fact(n),b=inv(fact(n-r));return (a*b)%mod;}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll ii;for(ii=2;ii*ii<=a;ii++){if(a%ii==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll ii,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(ii,3,x+1)fibo[ii]=fibo[ii-1]+fibo[ii-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=1,tmp=n;while(tmp/10>0){tmp/=10;d++;}return d;}
/*行列のコピー*/void matcpy(ll a[S][S],ll b[S][S]){ll ii,jj;rep(ii,0,S)rep(jj,0,S)b[ii][jj]=a[ii][jj];/*(aをbに)*/}
/*行列のリセット*/void matrst(ll a[S][S]){ll ii,jj;rep(ii,0,S)rep(jj,0,S)a[ii][jj]=0;}
/*行列の2乗*/void matpow(ll a[S][S]){ll ans[S][S];matrst(ans);ll ii,jj,kk;rep(ii,0,S)rep(jj,0,S)rep(kk,0,S){ans[ii][jj]+=a[ii][kk]*a[kk][jj];ans[ii][jj]%=mod;}matcpy(ans,a);}
/*行列の乗算*/void matmul(ll a[S][S],ll b[S][S], ll as[S][S]){ll ii,jj,kk;matrst(as);rep(ii,0,S)rep(jj,0,S)rep(kk,0,S){as[ii][jj]+=a[ii][kk]*b[kk][jj];as[ii][jj]%=mod;}}
/*迷路移動*/const int dx[4]={1,0,-1,0};const int dy[4]={0,1,0,-1};
llfor;////////////////////////////////////////////////////////////
int main(){
 ll n;
 cin>>n;
 vector<ll>a(n);
 ll xo[80][2];
 rep(i,0,61){
  rep(j,0,2){
   xo[i][j]=0;
  }
 } 

 rep(j,0,n){
  cin>>a.at(j);
 }
 rep(j,0,n){
  rep(i,0,61){
   if(a[j]<(1LL<<i))xo[i][0]++;
   else if(a[j]&(1LL<<i))xo[i][1]++;
   else xo[i][0]++;
  }
 }
 ll ans=0;
 rep(j,0,61){
  ans+=((((llpow(2,j)%mod)*xo[j][0])%mod)*xo[j][1])%mod;
  ans%=mod;
 }
 pr(ans);

return 0;}
