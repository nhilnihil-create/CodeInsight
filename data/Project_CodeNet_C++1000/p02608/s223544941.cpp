/*		Author : Kaustubh Gangwar
		||S||A||M||R||A||T||
*/
#include <bits/stdc++.h>
using namespace std;
#define modo 1000000007
#define ff first
#define ss second 
#define ld long double
#define pb push_back
#define gcd __gcd
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(),(x).end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define nl '\n'
typedef long long  ll;
typedef pair<int,int> pii;

ll bpow(ll a, ll b) {
	a=a; ll res = 1;
    while(b){
        if (b & 1)
        res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve(ll n)
{	ll a[n+1]={0};
	fe(i,1,100)
	{
		fe(j,1,100)
		{
			fe(k,1,100)
			{
				if(i*i+j*j+k*k+i*j+j*k+k*i<=n)
				a[i*i+j*j+k*k+i*j+j*k+k*i]++;
			}
		}
	}
	fe(i,1,n)
	cout<<a[i]<<nl;
	
	
}

int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll test=1;
//	cin>>test;
	while(test--)
	{
		ll n; cin>>n;
		solve(n);
		
	}
return 0;
}
