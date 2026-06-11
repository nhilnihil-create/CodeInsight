#include<bits/stdc++.h>
using namespace std;

int find_parent(int i,int par[])
{
    if(i==par[i])
        return i;
        
    return par[i]=find_parent(par[i],par);
}

int main()
{
  	int n,m;
  	cin>>n>>m;
  	
  	int par[n];
  	int sz[n];
  	
  	for(int i=0;i<n;i++)
  	{
  	    par[i]=i;
  	    sz[i]=1;
  	}
  	
  	int ma=1;
  	int a,b;
  	
  	for(int i=0;i<m;i++)
  	{
  	    cin>>a>>b;
  	    a--,b--;
  	    
  	    a=find_parent(a,par);
  	    b=find_parent(b,par);
  	    
  	    if(a!=b)
  	    {
  	        par[b]=a;
  	        sz[a]+=sz[b];
  	        
  	        ma=max(ma,sz[a]);
  	    }
  	}
  	
  	cout<<ma<<endl;
  	return 0;
}