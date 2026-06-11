// vjusge5
#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> u, int x)
{
for(int i=0;i<u.size();i++)
{
if(u[i]<x)
	return false;
}
return true;
}


int main()
{
    int n,flag=0,y,m,x,ans=INT_MAX;
    cin>>n>>m>>x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<=m;j++)
    {
    if(j==0)
    cin>>c[i];
    else
    cin>>a[i][j-1];	
    }
    }
   
    int tot=1<<n;
    int cost;
    
    for(int mask=0;mask<tot;mask++)
    {
    vector<int> u(m,0);
    cost=0;
    for(int i=0;i<n;i++)
    {
    if((mask&(1<<i))!=0)
    {
    cost+=c[i];
    for(int j=0;j<m;j++)
    u[j]+=a[i][j];
    }	
    }
    if(check(u,x))
    {
    flag=1;
    ans=min(ans,cost);	
    }
    }
    if(flag==0)
    	cout<<-1;
    else
        cout<<ans;
    
	return 0;
}
