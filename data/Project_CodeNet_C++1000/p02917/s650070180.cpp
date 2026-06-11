#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    int n;
    cin>>n,n--;
    int a[n];
    for(auto &it:a)   cin>>it;
    ll ans=a[0];
    for(int i=0;i<n-1;i++){
        ans+=min(a[i],a[i+1]);
    }
    ans+=a[n-1];
    cout<<ans<<endl;
}
