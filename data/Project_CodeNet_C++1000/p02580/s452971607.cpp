#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const int MAXN=3e5+10;
const ll MOD=10;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
int H,W,M;
int col[MAXN];
int row[MAXN];
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>H>>W>>M;
    set<pair<int,int>>tgt;
    for(int u=0;u<M;u++){
        int h,w;
        cin>>h>>w;
        tgt.insert({h,w});
        row[h]++;
        col[w]++;
    }
    vector<pair<int,int>>r,c;
    for(int u=1;u<=H;u++){
        if(row[u])r.push_back({row[u],u});
    }
    for(int u=1;u<=W;u++){
        if(col[u])c.push_back({col[u],u});
    }
    sort(r.begin(),r.end());
    reverse(r.begin(),r.end());
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int ans=0;
    int acr=r.front().first;
    for(auto p:c){
        int t=acr+p.first;
        if(tgt.count({r.front().second,p.second}))t--;
        ans=max(ans,t);
    }
    acr=c.front().first;
    for(auto p:r){
        int t=acr+p.first;
        if(tgt.count({p.second,c.front().second}))t--;
        ans=max(ans,t);
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}