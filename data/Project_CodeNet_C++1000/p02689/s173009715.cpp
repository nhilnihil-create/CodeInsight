#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll; 

ll inf =1e9+7;

#define pi 3.14159265358979323846L
bool isprime(ll a)
{
	
	ll cnt=0;	
	for(ll i=1;i*i<a;i++)
	{
		
	 	if(a%i==0)
	 	{
	 		cnt+=2;
		 }
		
		
	}
	
		if(cnt==2)
		return true;
		else
		return false;
		
}
ll mod(ll a)
{
	if(a<inf)return a;
	else
	return a%inf;
}
void solve()
{

ll n,m;
cin>>n>>m;
ll ele[n];

for(ll i=0;i<n;i++)cin>>ele[i];


vector<set<ll> >path(n+1);
for(ll i=0,x,y;i<m;i++)
{
	cin>>x>>y;
	path[x].insert(y);
	path[y].insert(x);
}

ll good=0;
bool notgood[n+1]={false};

for(ll i=1;i<=n;i++)
{
	if(notgood[i])continue;
	ll cnt=0;
	
	for(auto p: path[i])
	{
		if(ele[i-1]>ele[p-1])
		{
			notgood[p]=true;
			cnt++;
		}
	}
	if(cnt==path[i].size())good++;
}

cout<<good;


}

int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	
