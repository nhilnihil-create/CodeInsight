#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod  = 1000000007;
ll qpow(int a,int b){
    ll ret = 1;
    while(b){
        //cout << b%2 << endl;
        if(b%2) ret=(ret*a)%mod;
        a=(1ll*a*a)%mod;
        b/=2;
    }
    return ret;
}
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    ll ret = qpow(2,n);
    a=min(a,n-a);
    ll num = 1;
    for(int i=1;i<=a;i++)
        num=(num*i)%mod;
    ll num2 = 1;
    for(int i=n-a+1;i<=n;i++)
        num2=(num2*i)%mod;
    ret-=num2*qpow(num,mod-2)%mod;
    num =1;
    b=min(b,n-b);
    for(int i=1;i<=b;i++)
        num=(num*i)%mod;
    num2 = 1;
    for(int i=n-b+1;i<=n;i++)
        num2=(num2*i)%mod;
    ret-=num2*qpow(num,mod-2)%mod+1;
    cout << (ret%mod+mod)%mod << endl;
    return 0;
}
