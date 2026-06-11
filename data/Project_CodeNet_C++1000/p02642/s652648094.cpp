#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define hahashad ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
#define VL vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define what(A) cout<<#A<<" is "<<A<<endl;
ll isprime[1000005];
ll ans;
void divisors()
{
    FOR(i,1,1e6+1)
    {
        if(isprime[i]==0)
            continue;
        if(isprime[i]==1)
        {
            ans++;
        }
        for(ll j=2*i;j<=1e6;j+=i)
        {
            isprime[j]=0;
        }
    }
}

int main()
{
	ll n;
	cin >> n;
	FOR(i, 0, n)
	{
		IN(inp)
		isprime[inp]++;
	}
    divisors();
    cout<<ans;
}