#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod=1e9 +7;
#define vi vector<int>
#define pb emplace_back
ll poww(ll n,ll x)
{
    ll res=1;
    
    while(x>0)
    {
        if(x&1)
          res*=n;
        
        x=x>>1;
        n*=n;
    }
    return res;
}

ll parent[2000005];
ll size1[2000005];
int find(int node)
{
	if(parent[node]<0)
	  return node;
	 
	return parent[node]= find(parent[node]);
}

void union1(ll a,ll b)
{
	a=find(a);
	b=find(b);
	
	
	if(a!=b)
	{
		 if(size1[a]>size1[b])
	      swap(a,b);
	    
	    size1[a]+= size1[b];
		parent[b]=a;
	}
	   
}


int main() 
{
	   ios::sync_with_stdio(0);
	   cin.tie(0);
	   cout.tie(0);
       
       ll n,m,x,y;
       cin>>n>>m;
       for(int i=0;i<n;i++)
       {
       	  parent[i]=-1;
       	  size1[i]=1;
       }
       
       while(m--)
       {
       	cin>>x>>y;
       x--,y--;
       	union1(x,y);
       }
       
       map<ll,ll> mp1;
       for(int i=1;i<=n;i++)
       {
       	//cout<<parent[i]<<' ';
       	mp1[parent[i]]++;
       }
      // cout<<endl;
       
       ll mx=0;
       for(int i=0;i<n;i++)
           mx=max(size1[i],mx);
       cout<<mx;
//        
       
}