#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
   ll n,k;
   cin>>n>>k;
   ll ans = (ll)(floor(log(n)/log(k)) + 1);
   cout<<ans<<"\n";
}