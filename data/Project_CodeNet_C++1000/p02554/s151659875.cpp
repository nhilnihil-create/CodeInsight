#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
#define ios ios::sync_with_stdio(false)
#define mem(arr) memset(arr,0,sizeof(arr))
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7; 
ll ksm(ll a, ll b, ll p)
{
    ll res = 1;
    while(b)
	{
        if (b&1) 
			res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main()
{
	int n;
	ll ans;
    cin>>n;
    ans = ((ksm(10,n,mod) % mod + ksm(8,n,mod) % mod - (2 * (ksm(9,n,mod) % mod)) % mod) + mod) % mod;
    cout<<ans<<endl;
    return 0;
}
