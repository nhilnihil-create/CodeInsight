#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
map<P,bool> mp;
int main(){
int n;
cin>>n;
V<P> d(n);
for(int i=0;i<n;i++){
   cin>>d[i].fi>>d[i].se;
   mp[d[i]]=1;
}
int ans=n;
for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
      if(i==j)continue;
         ll a=d[j].fi-d[i].fi;
         ll b=d[j].se-d[i].se;
         int res=0;
         for(int k=0;k<n;k++){
            if(!mp[P(d[k].fi-a,d[k].se-b)])res++;
         }
         chmin(ans,res);
   }
}
cout<<ans<<endl;
}