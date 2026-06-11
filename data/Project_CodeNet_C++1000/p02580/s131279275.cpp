#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
#define pll pair<ll,ll>
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

map<ll,ll> hb,wb,hb2,wb2;
map<pair<ll,ll>,ll> p;
int main(){
    ll h,w,H,W,M,ans=0;
    cin>>H>>W>>M;
    rep(i,0,M){
        cin>>h>>w;
        hb[h]++;
        wb[w]++;
        p[mp(h,w)]++;
    }
    ll hmax=0,wmax=0;
    bool f=false;
    for(auto i:hb)hmax=max(hmax,i.second);
    for(auto i:wb)wmax=max(wmax,i.second);
    for(auto i:hb){
        if(i.second==hmax)hb2[i.first]=1;
    }
    for(auto i:wb){
        if(i.second==wmax)wb2[i.first]=1;
    }
    for(auto i:hb2){
        if(f)break;
        if(i.second==1){
            for(auto j:wb2){
                if(j.second==1&&p[mp(i.first,j.first)]==0)f=true;
                if(f)break;
            }
        }
    }
    if(!f)hmax--;
    cout<<hmax+wmax;
}

