#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+100;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll t,n,k,a[maxn];
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++) res+=i*(n+1-i);
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        res-=u*(n+1-v);
    }cout<<res<<endl;
    return 0;
}
