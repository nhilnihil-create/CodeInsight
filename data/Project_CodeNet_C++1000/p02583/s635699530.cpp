#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
int main() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)    cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            for(ll k=j+1;k<=n;k++){
                if(a[i]!=a[j]&&a[j]!=a[k]){
                    if(a[i]+a[j]>a[k]){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
