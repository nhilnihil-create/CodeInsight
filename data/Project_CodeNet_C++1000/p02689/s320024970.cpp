
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
vector<int> ar[100001];
int a[100001];

int main()
{
   ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
int x,y;
while(m--)
{
	cin>>x>>y;
	ar[x].pb(y);
	ar[y].pb(x);
}
int ans=0;
for(int i=1;i<=n;i++)
{
	if(ar[i].size()==0)
	{
		ans++;
	}
	else
	{
		int flag=1;
		for(int res:ar[i])
		{
			if(a[i]<=a[res])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
	
			ans++;
		}
	}
}
cout<<ans<<endl;
}

