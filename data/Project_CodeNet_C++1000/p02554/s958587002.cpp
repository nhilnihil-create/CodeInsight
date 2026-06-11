#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll n;
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
            if(b&1){
                 ans*=a;
            ans%=mod;
            }

            a*=a;
            a%=mod;
            b>>=1;
    }
return ans;
}
int main()
{
    cin>>n;
    cout<<(ksm(10,n)%mod-2*ksm(9,n)%mod+ksm(8,n)%mod+mod)%mod<<endl;
    return 0;
}
////刷题！！！！！！！！！！！！！！！！
