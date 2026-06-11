#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[200005];
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n%2==0){
        for(int i=0;i<n/2;i++){
            ans+=(a[n-1-i]*2);
        }
        ans-=a[n-1];
        cout<<ans<<endl;
    }else{
        for(int i=0;i<=n/2;i++){
            ans+=(a[n-1-i]*2);
        }
        ans-=(a[n-1]+a[n-1-n/2]);
        cout<<ans<<endl;
    }
    
}

