#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
#define mod 1000000007
//#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT{
    __INIT(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout<<fixed<<setprecision(15);
    }
}__init;


int main(){
    ll h,w,m;
    cin>>h>>w>>m;
    vector<pl> ngo;
    vl tate(h,0);
    vl yoko(w,0);
    ll tatemax = 0;
    ll yokomax = 0;
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        ngo.push_back({a,b});
        tate[a]++;
        yoko[b]++;
        tatemax = max(tatemax,tate[a]);
        yokomax = max(yokomax,yoko[b]);
    }
    vl tatems,yokoms;
    rep(i,h) if(tate[i] == tatemax) tatems.push_back(i);
    rep(i,w) if(yoko[i] == yokomax) yokoms.push_back(i);
    ll kosu = (ll)(tatems.size())*(ll)(yokoms.size());
    rep(i,m){
        if(binary_search(all(tatems),ngo[i].first) && binary_search(all(yokoms),ngo[i].second)){
            kosu--;
        }
    }
    if(kosu == 0){
        cout<<(tatemax+yokomax-1)<<endl;
    }
    else{
        cout<<(tatemax+yokomax)<<endl;
    }
    return 0;
}