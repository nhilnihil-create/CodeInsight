#include<bits/stdc++.h>
using namespace std;
#define mx 10000010
typedef long long ll;
ll dv[mx];
void divisors()
{
    ll i,j,c;
    for(i=1;i<=mx;i++)
    {
        for(j=i;j<=mx;j+=i)dv[j]++;
    }
}
int main()
{
    ll n,sum=0;
    divisors();
    cin>>n;
    for(ll i=1;i<=n;i++)sum+=i*dv[i];
    cout<<sum<<endl;
    return 0;
}
