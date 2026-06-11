#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
#define reps(i,n) for(ll i=1;i<=(n);++i)
using ll = long long;
using str = string;
constexpr long long INF = (1LL<<60);
constexpr long long MOD = (1e9+7);
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
inline void dump(){cout<<endl;}
template<class Head,class... Tail>inline void dump(Head&& head, Tail&&... tail){cout<<head<<", ";dump(forward<Tail>(tail)...);}
template<typename T>inline istream &operator>>(istream&input,vector<T>&v){for(auto &elemnt:v)input>>elemnt;return input;}

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  
  ll n;
  cin>>n;
  vector<long double> x(n),y(n);
  rep(i,n)cin>>x[i]>>y[i];

  vector<pair<long double,ll>> a(n);
  long double sx=0.0,sy=0.0;
  rep(i,n){
    sx+=x[i];
    sy+=y[i];
    a[i].first=atan2(x[i],y[i]);
    a[i].second=i;
  }
  sort(a.begin(),a.end());

  long double ans=0.0;
  rep(i,n)rep(j,n){
    long double xx=0.0,yy=0.0;
    for(ll k=i;k<=j;++k){
      xx+=x[a[k].second];
      yy+=y[a[k].second];
    }
    long double tmp=sqrt(xx*xx+yy*yy);
    long double _x=sx-xx,_y=sy-yy;
    chmax(tmp,sqrt(_x*_x+_y*_y));
    chmax(ans,tmp);
  }

  cout<<(ans)<<endl;
  
  
}
