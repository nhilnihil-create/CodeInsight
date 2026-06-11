#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
const int MAXN=1e5+10;
int n;
int p[MAXN];
int pos[MAXN];
int lp[MAXN];
int rp[MAXN];
int main()
{
    // freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int u=1;u<=n;u++){
        cin>>p[u];
        pos[p[u]]=u;
        lp[u]=u-1;
        rp[u]=u+1;
    }
    ll ans=0;
    for(int idx=1;idx<=n;idx++){
        ll lp1=(ll)lp[pos[idx]];
        ll lp2=(ll)lp[lp1];
        ll rp1=(ll)rp[pos[idx]];
        ll rp2=(ll)rp[rp1];
        if(lp1!=0)ans+=(ll)idx*(lp1-lp2)*(rp1-pos[idx]);
        if(rp1!=n+1)ans+=(ll)idx*(pos[idx]-lp1)*(rp2-rp1);
        lp[rp1]=lp1;
        rp[lp1]=rp1;
    }
    cout<<ans;
}