#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD=1e9+7;
#define nl '\n'
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll po(ll n,ll a)
{
    ll r=1;
    for(int i=1; i<=a; i++)
    {
        r*=n;
        r%=MOD;
    }
    return r%MOD;
}

int main()
{
    fio;
    ll n,a;
    cin>>n;

    a=po(10LL,n)%MOD;
    a-=(2*(po(9LL,n)-MOD));
    a%=MOD;
    a+=(po(8LL,n));
    a%=MOD;

    cout<<a<<nl;
    return 0;
}
