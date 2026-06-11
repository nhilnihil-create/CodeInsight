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
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
llfor;
/*pi*/double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll ans=1;rep(i,0,n){ans*=x;}return ans;}
/*階乗*/ll fact(ll x){ll ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){ll ans=1;rrp(i,n-r+1,n+1){ans*=i;}return ans/=fact(r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=0;i=0;while(n/10>0){i++;d++;}return d;}
ll ans=0;ll mod=llpow(10,9)+7;
////////////////////////////////////////////////////////////
ll n,m;
bool a[200000];
int main(){
 cin>>n>>m;
 ll b;
 rep(i,0,n)a[i]=false;
 rep(j,1,m+1){
  sc(b);
  a[b]=true;
 }
 
 ll step[n+10]={0};
 step[0]=1;
 if(!a[1])step[1]=1;
 rep(i,2,n+1){
  step[i]=step[i-2]+step[i-1];
  step[i]%=mod;
  if(a[i])step[i]=0;
 // cout<<i<<" "<<a[i]<<" "<<step[i]<<endl;
 }
 pr(step[n]);
return 0;}