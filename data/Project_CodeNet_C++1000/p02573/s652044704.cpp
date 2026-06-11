#include <iostream>
#include<bits/stdc++.h>
using namespace std;

# define ll long long int 

const int md = 1e9+7;
ll Parent[200005];
ll sze[200005];

void Build(int n)
{ for(ll i=1;i<=n;i++)
   { Parent[i]=i;
     sze[i]=1;
   }
}


ll find(ll u)
{
    if(Parent[u]==u) return u;
    else
    {
        return Parent[u]=find(Parent[u]);
    }
}



void Union(ll a, ll b)
{
  ll P_a=  find(a);
  ll P_b=  find(b);
  
  if(P_a!=P_b)
  {
  	sze[P_b]+=sze[P_a];
  	Parent[P_a]=Parent[P_b];
  }

}

int main()
{
    ll n,m;
    cin>>n>>m;
    
     //std::vector<Edge> E(m) ;
     Build(n);
     
     // for(ll i=0;i<m;i++)
     // {
     //     cin>>E[i].src;
     //     E[i].src--;
     //     cin>>E[i].dest;
     //     E[i].dest--;
     //     cin>>E[i].wt;
     // }

     for(int i=0;i<m;i++)
     {
     	ll x,y;
     	cin>>x>>y;
     	Union(x,y);
     }
      
      unordered_map<int,int> mp;
      ll mx=0;

     for(int i=1;i<=n;i++)
     {
     	int p=find(i);
     	//cout<<p<<endl;
     	if(mp.find(p)==mp.end())
     	{
     		mp[p]=1;
     		mx= max(mx,sze[p]);

     	}
     }


     
     
 
     
     cout<<mx<<endl;
    
    
}



