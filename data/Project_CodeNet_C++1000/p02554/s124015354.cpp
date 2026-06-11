#include <bits/stdc++.h>
#define NMAX 200005

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll binPow(ll a, ll p){
    ll ans=1;
    while(p){
        if(p&1) ans=ans*a%MOD;
        p>>=1;
        a=a*a%MOD;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    cout<<(binPow(10,n)+binPow(8,n)-2*binPow(9,n)+MOD*2)%MOD;
    return 0;
}
