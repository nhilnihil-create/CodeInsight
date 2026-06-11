
#include<bits/stdc++.h>
#include<cmath>
#define SZ(x) ((int)x.size())
#include<vector>
#include<set>
#include<map>
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#include<string>
#include<cctype>
#include<queue>
#define ii pair<int,int>
#include <sstream>
#define lli long long int
#define pairs pair<int,int>
#define mod 1000000007
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
ll pows(ll a,ll n,ll m)
{
	ll res=1;
	while(n)
	{
	if(n%2!=0)
	{
		res=(res*a)%m;
		n--;
		}
		else
		{
			a=(a*a)%m;
			n=n/2;
			}	
	}
	return res%m;
}
ll  gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else 
	return gcd(b,a%b);
}
bool isprime(ll n)
{
	if(n==1)
	{
		return false;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
bool istrue(string s)
{
	int i=0;
	int j=s.size()-1;
	while(i<j)
	{
	if(s[i]==s[j])
	{
		i++;
		j--;
		}
		else
		{
			return false;
			}	
	}
	return true;
}
int main()
{
   ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    if(isprime(n)==true)
    {
    	cout<<1<<endl;
    	return 0;
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
vector<ll>vi;
for(ll i=2;i*i<=n;i++)
{
	if(n%i==0)
	{
		int cnt=0;
		while(n%i==0)
		{
			cnt++;
			n=n/i;
		}
		vi.pb(cnt);
	}
}
if(n>1)
{
	vi.pb(1);
}
int ans=0;
for(ll i=0;i<vi.size();i++)
{
	int p=vi[i];
	for(ll j=1;j<=50;j++)
	{
		if(p<j)
		{
			break;
		}
		else
		{
			ans++;
			p=p-j;
		}
	}
}
cout<<ans<<endl;
}
 
