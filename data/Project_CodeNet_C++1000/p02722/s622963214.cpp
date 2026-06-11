#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,ans=2;
    cin>>n;
    if(n==2) ans=1;
    for(ll k=2;k*k<=n;k++){
        ll m=n;
        while(m>=k) m%k?m%=k:m/=k;
        if(m==1) ans++;
        if((n-1)%k==0&&k*k!=(n-1) ) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
