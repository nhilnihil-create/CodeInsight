
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
vector<ll>vi;
for(ll i=0;i<=130;i++)
{
	vi.pb(pow(i,5));
}
vector<ll>vii;
for(ll i=0;i>=-130;i--)
{
	vii.pb(pow(i,5));
}
for(int i=0;i<vi.size();i++)
{
	for(int j=0;j<vi.size();j++)
	{
		if(vi[i]-vi[j]==n)
		{
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		if(vi[j]-vi[i]==n)
		{
			cout<<j<<" "<<i<<endl;
			return 0;
		}
	}
}
for(int i=0;i<vii.size();i++)
{
	for(int j=0;j<vii.size();j++)
	{
		if(vii[i]-vii[j]==n)
		{
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		if(vii[j]-vii[i]==n)
		{
			cout<<j<<" "<<i<<endl;
			return 0;
		}
	}
}
for(int i=0;i<vi.size();i++)
{
	for(int j=0;j<vii.size();j++)
	{
		if(vi[i]-vii[j]==n)
		{
			cout<<i<<" "<<-(j)<<endl;
			return 0;
		}
		if(vi[j]-vii[i]==n)
		{
			cout<<j<<" "<<i<<endl;
			return 0;
		}
	}
}
}

