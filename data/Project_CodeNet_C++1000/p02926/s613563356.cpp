#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<endl;}
template<class T> void outvp(T v){rep(i,v.size())outp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
int main(){
    ll n;cin>>n;
    vector<vector<double>> v(n*2,vector<double>(3,400));
    rep(i,n)cin>>v[i][1]>>v[i][2];
    rep(i,n){
        if(v[i][1]!=0){
            v[i][0]=atan(v[i][2]/v[i][1])/pi*180;
            if(v[i][2]/v[i][1]<0)v[i][0]+=180;
        }
        else v[i][0]=90;
        if(v[i][2]<0||v[i][2]==0&&v[i][1]<0)v[i][0]+=180;
    }
    sort(all(v));
    rep(i,n){
        v[i+n][0]=v[i][0]+360;
        rep(j,2)v[i+n][j+1]=v[i][j+1];
    }
    vector<double> x(2*n+1),y(2*n+1);
    rep(i,n*2){
        x[i+1]=x[i]+v[i][1];
        y[i+1]=y[i]+v[i][2];
    }
    double ans=0;
    rep(i,n){
        rep(j,n)chmax(ans,(x[i+j+1]-x[i])*(x[i+j+1]-x[i])+(y[i+j+1]-y[i])*(y[i+j+1]-y[i]));
    }
    cout<<fixed<<setprecision(15);
    out(sqrt(ans));
}