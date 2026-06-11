#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e6+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=1000001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
map<int,int>mp;
vector<int>pr;
int p[maxn];
void sieve()
{
  ll i,j;
  for(i=2;i<maxn;i++)
  {
  	if(p[i]==0)
  	{
  		pr.pb(i);
  		for(j=i*i;j<maxn;j+=i)
  			p[j]=1;
  	}
  }

 
}
int main()
{
	fastio;
	//int t;
	sieve();
	ll int i,j,k,n,m,g=0;
	cin>>n;
	ll a[n];
	
	for(i=0;i<n;i++){
		cin>>a[i];
		g=__gcd(g,a[i]);
		mp[a[i]]++;
	}
	int j1=1;
for(i=0;i<pr.size();i++)
{
	k=0;
	ll i1=pr[i];
	for(j=i1;j<maxn;j+=i1)
	{
       k+=mp[j];
	}
	
	if(k>=2)
		{
			j1=0;
			break;


		}
}
//cout<<j<<" ";
if(j1==1)
{
cout<<"pairwise coprime";
}
else if(g==1)
{
	cout<<"setwise coprime";

}
else
{
    cout<<"not coprime";
}

	
	

}
//Lordvishnu@almighty