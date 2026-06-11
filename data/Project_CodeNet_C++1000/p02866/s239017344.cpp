#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod=998244353;
ll power(ll n,ll p){
    ll ans=1;
    while(p){
        if(p&1)ans=(ans*n)%mod;
        n=(n*n)%mod;
        p>>=1;
    }
    return ans;
}
ll n,mx,a[100005],ans=1,freq[100005];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],freq[a[i]]++,mx=max(mx,a[i]);
    if(a[1]!=0 || freq[0]!=1)return cout<<"0" , 0;
    for(ll i=1;i<=mx;i++)ans=(ans * power(freq[i-1],freq[i]) )%mod;
    cout<<ans;
}


