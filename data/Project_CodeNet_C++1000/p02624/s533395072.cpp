#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
vector<ll> factors;
ll n;
void seive()
{
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j+=i)
    factors[j]++;
}
int main()
{
   cin>>n;
   factors.resize(n+1);
   seive();
   ll ans=0;
   for(ll i=1;i<=n;i++)
   ans+= i*factors[i];
   
   cout<<ans<<endl;
    
}