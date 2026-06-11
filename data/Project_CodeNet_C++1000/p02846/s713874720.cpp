#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll inf=1000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll t[2];rep(i,0,2)cin>>t[i];
    ll a[2],b[2];
    rep(i,0,2)cin>>a[i];
    rep(i,0,2)cin>>b[i];
    ll l[2];
    if(a[0]<b[0]){
        swap(a[0],b[0]);
        swap(a[1],b[1]);
    }
    l[0]=a[0]*t[0]-t[0]*b[0];
    l[1]=b[1]*t[1]-t[1]*a[1];
    if(l[0]>l[1]){
        cout<<0<<endl;
        return 0;
    }
    if(l[0]==l[1]){
        cout<<"infinity"<<endl;
        return 0;
    }
    ll u=l[1]-l[0];
    ll y=l[0]/u;
    y*=2;
    if(l[0]%u!=0)y++;
    cout<<y<<endl;
}
