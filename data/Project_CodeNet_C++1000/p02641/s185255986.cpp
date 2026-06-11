
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
int n,x;
cin>>x>>n;
set<int>s;
int l;
for(int i=0;i<n;i++)
{
	cin>>l;
	s.insert(l);
}
if(n==0)
{
	cout<<x<<endl;
	return 0;
}
int cnt1=0;
int cnt2=0;
int ans1=0,ans2=0;
for(int i=x;i<=110;i++)
{
	if(s.find(i)==s.end())
	{
		ans1=i;
	break;
}
	else
	cnt1++;
}
for(int i=x;i>=0;i--)
{
	if(s.find(i)==s.end())
	{
		ans2=i;
		break;
	}
	else
	{
	cnt2++;
		
	}
}
if(cnt1<cnt2)
{
	cout<<ans1<<endl;
}
else
cout<<ans2<<endl;
    
}


