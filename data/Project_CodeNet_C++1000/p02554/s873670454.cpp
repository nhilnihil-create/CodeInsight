#include <stdio.h>
#include <string.h>
#include <iostream>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int MAXN=1100;
const ll MOD=1e9+7;
ll n;
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}
int main()
{
    ios;
    cin>>n;
    cout<<((ksm(10,n)-ksm(9,n)*2+2*MOD)%MOD+ksm(8,n))%MOD<<'\n';
    return 0;
}