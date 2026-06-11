#define TEMPLATE_USED
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

void solve(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];

    ll sum=0;
    ll idx0=-1,idxp=-1,idxn=-1;
    rep(i,n){
        if(a[i]==0)idx0=i;
        if(a[i]>0&&(idxp==-1||a[i]<a[idxp]))idxp=i;
        if(a[i]<0&&(idxn==-1||a[i]>a[idxn]))idxn=i;
        sum+=abs(a[i]);
    }

    if(idxp==-1&&idxn==-1){
        cout<<0<<endl;
        rep(i,n-1)cout<<"0 0"<<endl;
        return;
    }

    if(idxp==-1&&idx0==-1){
        cout<<sum+2*a[idxn]<<endl;
        rep(i,n){
            if(i==idxn)continue;
            cout<<a[idxn]<<' '<<a[i]<<endl;
            a[idxn]-=a[i];
        }
        return;
    }

    if(idxn==-1&&idx0==-1){
        cout<<sum-2*a[idxp]<<endl;
        rep(i,n){
            if(i==idxp||i==(idxp==0))continue;
            cout<<a[idxp]<<' '<<a[i]<<endl;
            a[idxp]-=a[i];
        }
        cout<<a[idxp==0]<<' '<<a[idxp]<<endl;
        return;
    }

    if(idxp==-1)idxp=idx0;
    if(idxn==-1)idxn=idx0;
    cout<<sum<<endl;
    rep(i,n){
        if(i==idxp||i==idxn)continue;
        if(a[i]>0){
            cout<<a[idxn]<<' '<<a[i]<<endl;
            a[idxn]-=a[i];
        }else{
            cout<<a[idxp]<<' '<<a[i]<<endl;
            a[idxp]-=a[i];
        }
    }
    cout<<a[idxp]<<' '<<a[idxn]<<endl;
}