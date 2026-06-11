#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300009;
const int MOD=1e9+7;
ll a[N],n,ans;
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<60;i++) {
        ll x=0;
        for(int j=0;j<n;j++) if((a[j]>>i)&1) x++;
        ll t=x*(n-x)%MOD;
        for(int j=0;j<i;j++) t=(t<<1)%MOD;
        ans=(ans+t)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}