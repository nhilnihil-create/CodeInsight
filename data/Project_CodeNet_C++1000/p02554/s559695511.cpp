#include <iostream>
using namespace std;
const int mod=1e9+7;
int n;
long long base1=8,base2=9,base3=10;
void mut(long long &base)
{
    long long k=base;
    for(int i=1;i<n;i++)base=(base*k)%mod;
}
int main(void)
{
    cin>>n;
    mut(base1);
    mut(base2);
    mut(base3);
    long long ans=base1+base3-2*base2;
    ans%=mod;
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}