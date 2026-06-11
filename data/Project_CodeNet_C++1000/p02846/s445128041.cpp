#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  ll t1,t2;
  cin>>t1>>t2;
  ll a1,b1,a2,b2;
  cin>>a1>>b1>>a2>>b2;
  if(a1<a2){
      swap(a1,a2);swap(b1,b2);
  }
   if(a1==a2){
      cout<<"infinity"<<endl;
      return 0;
  }
  if(a1*t1+b1*t2<=a2*t1+b2*t2){
      if(a1*t1+b1*t2==a2*t1+b2*t2){
        cout<<"infinity"<<endl;
        return 0;
      }
      else{
          ll d=(a2*t1+b2*t2)-(a1*t1+b1*t2);
         // cout<<d<<endl;
          ll ans=(a1-a2)*t1/d*2+1-((a1-a2)*t1%d==0);
         cout<<ans<<endl;
      }
  }
  else{
      cout<<0<<endl;
  }
}

