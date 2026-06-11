#include<bits/stdc++.h>
using namespace std;
typedef  long long ll; 

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
	vector<set<ll>>path(n+1);
	
	
		for(ll i=0,x,y;i<m;i++)
	{
		cin>>x>>y;
	
	path[x].insert(y);
	path[y].insert(x);
		
	}
	
	queue<ll>q;
	ll b[n+1];
	bool visited[n+1]={false};
	
	q.push(1);
	b[1]=1;
	visited[1]=true;
	while(q.size()>0)
	{
		ll parent=q.front();
		q.pop();
		
		visited[parent]=true;
		
		
		for(auto child:path[parent])
		{
			if(visited[child])continue;
			
			b[child]=parent;
			q.push(child);
			visited[child]=true;
			
		}
		
	}
	
	
	cout<<"Yes\n";
	
	for(ll i=2;i<=n;i++)cout<<b[i]<<"\n";
	

}

int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	
