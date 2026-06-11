#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],p[100005];
set<ll> s;
int main(){
    ll n,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    s.insert(0);s.insert(n+1);
    for(ll i=n;i>=1;i--){
        auto x=s.upper_bound(p[i]);
        auto y=--s.upper_bound(p[i]);
        if(*y!=0){
            auto t=--y;y++;
            ans+=(*x-p[i])*(*y-*t)*i;
        }
        if(*x!=n+1){
            auto t=++x;x--;
            ans+=(p[i]-*y)*(*t-*x)*i;
        }
        s.insert(p[i]);
    }
    cout<<ans<<endl;
}