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
#include<string>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j,k
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define sort(a) sort(a.begin(),a.end())
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define sizeoof(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
ll ans=0;llfor;///////////////////////////////////////////////////////////
int main(){
 char s[110];sc(s);
 ll k;sc(k);
 ll len=strlen(s);
 ll ans=0; 
 ll flag;
 ll a=1,b=1;
 ll c=1;
 char aa=s[0],bb=s[len-1];
 rep(i,0,len){
  if(s[i]!=s[i+1])break;
  a++;
 }
 if(a==len){pr(a*k/2);return 0;}
 rrp(i,len,0){
  if(s[i]!=s[i-1])break;
  b++;
 }
 char now=s[0];
 rep(i,1,len){
  if(now==s[i])c++;
  else{
   now=s[i];
   ans+=c/2;
   //pr(c);cout<<"ans: "<<ans<<endl;
   c=1;
  }
  if(i==len-1){
   now=s[i];
   ans+=c/2;
   //pr(c);cout<<"ans: "<<ans<<endl;
  }
 }
 if(aa!=bb)ans*=k;
 else ans=ans*k-(a/2+b/2-(a+b)/2)*(k-1);
 pr(ans);
  return 0;}