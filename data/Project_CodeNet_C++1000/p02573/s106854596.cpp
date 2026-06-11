#include<bits/stdc++.h>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll f[N+1];
ll b[N+1];
ll finds(ll x){
    if(f[x]!=x)
        f[x]=finds(f[x]);
    return f[x];
}
void uni(ll x,ll y){
    ll x1=finds(x);
    ll y1=finds(y);
    ll a=min(x1,y1);
    ll b=max(x1,y1);
    f[b]=f[a];

}
int main(){
    for(int i=1; i<N; i++){
        f[i]=i;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        uni(x,y);
    }
    ll maxs=-99999;
    for(int i=1; i<=n; i++){
        b[finds(i)]++;
    }
    for(int i=1; i<=n; i++){
        maxs=max(maxs,b[i]);
    }
    cout<<maxs<<endl;
    return 0;
}