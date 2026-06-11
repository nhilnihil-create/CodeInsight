#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1LL<<60;
long double pi=3.141592653589793238462643383279L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
double kaku(double x,double y){
    if(x==0){
        if(y>=0)return pi/2.0;
        else return 3*pi/2.0;
    }
    else{
        double ret=atan(y/x);
        if(x<0)ret+=pi;
        else if(y<0)ret+=2*pi;
        return ret;
    }
}
double dist(double a,double b,double c,double d){
    return pow(((a-c)*(a-c)+(b-d)*(b-d)),0.5);
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    double x[n],y[n];
    double ka[n];
    vector<double> v;
    rep(i,0,n){
        scanf("%lf %lf",&x[i],&y[i]);
        ka[i]=kaku(x[i],y[i]);
        v.push_back(ka[i]);
    }
    vector<double> w;
    rep(i,0,n){
        rep(j,i,n){
            double nk=(x[i]+x[j])/2.0;
            double ny=(y[i]+y[j])/2.0;
            w.push_back(kaku(nk,ny));
        }
        w.push_back(v[i]);
        w.push_back(v[i]+pi/2.0);
        w.push_back(v[i]-pi/2.0);
    }
    double noww=kaku(50000,1);
    double e=0;
    for(;;){
        w.push_back(e);
        e+=noww;
        if(e>=2*pi)break;
    }
    double di[n];
    rep(i,0,n)di[i]=dist(x[i],y[i],0,0);
    double ans=0;
    rep(j,0,w.size()){
        double now=w[j];
        double sum=0;
        rep(i,0,n){
            double si=ka[i];
            double sa=si-now;
            double r=di[i];
            r*=cos(sa);
            if(r>0)sum+=r;
        }
        ans=max(ans,sum);
    }
    
    cout<<fixed<<setprecision(15)<<ans<<endl;
    
}


