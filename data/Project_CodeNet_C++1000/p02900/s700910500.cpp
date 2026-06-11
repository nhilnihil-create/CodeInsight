#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;
const ll mod=1e6+7;


int main() {
ll n,m,g,ans=1;
cin>>n>>m;
vector<bool> prime(mod, true);

prime[0]=false;prime[1]=false;
g=__gcd(n,m);
for(ll i=2;i<mod;i++){
    if(prime[i]==false)continue;
    for(ll j=i*2;j<mod;j+=i)
    prime[j]=false;
    if(g%i)continue;
    while(g%i==0)g/=i;
    ans++;

    }
    if(g!=1)ans++;
cout<<ans;
}
