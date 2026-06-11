#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll n,cnt=0;
ll a[N],fa[N],b[N];
string s1,s2;
ll find(ll x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(ll x,ll y) {
    ll dx=find(x),dy=find(y);
    fa[dx]=dy;
}
int main() {
  //  freopen("../in.in", "r", stdin);
//    freopen("../out.out","w",stdout);
    ios::sync_with_stdio(false);
    ll t, i, j = 0;
    ll m, x, y,k;
    cin>>n>>m;
    for(i=1;i<=n;i++) fa[i]=i;
    for(i=0;i<m;i++){
        cin>>x>>y;
        add(x,y);
    }
    for(i=1;i<=n;i++) b[find(i)]++;
    ll maxn=0;
    for(i=1;i<=n;i++){
        maxn=max(b[i],maxn);
    }
    cout<<maxn<<endl;
    return 0;
}