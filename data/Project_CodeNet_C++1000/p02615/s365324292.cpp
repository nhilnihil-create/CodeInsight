
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
int vis[100001];
int dist[100001];
void bfs(int v)
{
	queue<int>q;
	vis[v]=1;
	dist[v]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(int child:ar[curr])
		{
			if(vis[child]==0)
			{
			vis[child]=1;
			dist[child]=dist[curr]+1;
			q.push(child);
		}
		}
	}
}
int main()
{
   ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[200001];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
ll sum=0;
sort(a,a+n);
sum=sum+a[n-1];
int k=n-2;
int cnt=n-2;
int cp=1;
while(k--)
{
	if(cp%3==0)
	{
		cnt--;
		cp=1;
		k++;
	}
	else
	{
		sum=sum+a[cnt];
		cp++;
	}
}
cout<<sum<<endl;
}
