#include<bits/stdc++.h>
#include<cmath>
#define SZ(x) ((int)x.size())
#include<vector>
#include<set>
#include<map>
#define ll long long
#define lli long long int
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
int  gcd(int a,int b)
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
int a[1000001];
int main()
{
   ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
set<int>vi;
int ans=0;
set<int>s;
for(int i=0;i<n;i++)
{
	int p=a[i];
	for(int j=2;j*j<=p;j++)
	{
		if(p%j==0)
		{
			s.insert(j);
			p=p/j;
			while(p%j==0)
			{
				p=p/j;
				if(p!=1)
				{
				s.insert(p);
			}
			}
		}
	}
	if(p>1)
	{
		s.insert(p);
	}
	ans=ans+s.size();
	for(int res:s)
	{
		vi.insert(res);
	}
	s.clear();
}
if(vi.size()==ans)
{
	cout<<"pairwise coprime"<<endl;
}
else
{
	int l=a[0];
	for(int i=1;i<n;i++)
	{
		l=gcd(a[i],l);
	}
	if(l==1)
	{
		cout<<"setwise coprime"<<endl;
	}
	else
	{
		cout<<"not coprime"<<endl;
	}
}
}
 
 