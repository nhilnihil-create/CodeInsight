#include <iostream>
using namespace std;
typedef long long ll;
ll a[200001],b[200001],MOD=1e9+7,n,k,ans;
int main(void){
    cin>>n>>k;
    for(ll i=1LL;i<=200000;i++){
        a[i]=a[i-1]+i;
        a[i]%=MOD;
    }
    b[0]=n;
    for(ll i=1LL;i<=n;i++){
        b[i]=n-i+b[i-1];
        b[i]%=MOD;
    }
    for(int i=k-1;i<=n;i++){
        ans+=b[i]-a[i]+1;
        //cout<<b[i]<<" "<<a[i]<<endl;
        ans%=MOD;
    }
    cout<<(ans+MOD)%MOD<<endl;
}
