#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
  ll n;
  cin>>n;
  V<ll> a(n),b(n);
  priority_queue<P> pq;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    cin>>b[i];
    pq.emplace(b[i]-a[i],i);
  }
  ll ans=0;
  while(pq.size()){
    auto p=pq.top();
    pq.pop();
    if(p.fi==0)continue;
    if(0<=p.fi-b[(p.se+n-1)%n]-b[(p.se+1)%n]){
      ll s=b[(p.se+n-1)%n],t=b[(p.se+1)%n];
      ans+=(p.fi)/(s+t);
      if((p.fi)/(s+t)==0){
          cout<<-1<<"\n";
          return 0;
      }
      b[p.se]-=(p.fi)/(s+t)*(s+t);
      p.fi%=(s+t);
      if(p.fi)pq.emplace(p.fi,p.se);
    }else{
      cout<<-1<<"\n";
      return 0;
    }
  }
  cout<<ans<<"\n";
}
