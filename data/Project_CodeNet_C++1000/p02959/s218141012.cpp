#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,ans=0;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=0;i<=n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        ll b;cin>>b;
        ans+=min(b,a[i]);
        b=max(b-a[i],(ll)0);
        if(b>0){
            ans+=min(a[i+1],b);
            a[i+1]=max(a[i+1]-b,(ll)0);
        }
    }
    cout<<ans<<endl;
}