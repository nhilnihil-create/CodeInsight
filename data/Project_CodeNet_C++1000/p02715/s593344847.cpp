#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<string,ll> si;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
#define sort(a) sort(a.begin(),a.end());
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define F first
#define S second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl "\n"
#define TC cin>>t;while(t--)
ll MOD = 1e9+7;
const ld PI = 3.1415926535898;
const ll LLMAX = LLONG_MAX;
const int N = 2e5+5;

ll power(int x, int y,int m) {
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2,m)%m;
    if (y%2 == 0)
        return ((temp)*(temp))%m;
    else
        return (((x)%m)*((temp*temp)%m))%m;
}

int main()
{
	ios
	int n,k;
	cin>>n>>k;
	int a[k+1]={0};
	for(int i=k;i>=1;i--)
	{
		a[i]=power(k/i,n,MOD)%MOD;
		ll extra=0;
		for(int j=2*i;j<=k;j+=i)
		{
			extra+=a[j];
			extra%=MOD;
		}
		a[i]+=(MOD-extra)%MOD;
		a[i]%=MOD;
	}
	ll sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=(i%MOD)*(a[i]%MOD);
		sum%=MOD;
	}
	cout<<sum<<nl;	
}