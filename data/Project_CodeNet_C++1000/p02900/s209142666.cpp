#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;
const ll mod=1e6+7;


int main() {
ll n,m,g,ans=1;
cin>>n>>m;



g=__gcd(n,m);
for(ll i=2;i<mod;i++){
    if(g%i)continue;
    while(g%i==0)g/=i;ans++;


    }
    if(g!=1)ans++;
cout<<ans;
}
