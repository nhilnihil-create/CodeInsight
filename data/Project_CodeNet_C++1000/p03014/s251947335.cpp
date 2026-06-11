#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll power(ll x, ll  y)  {  ll res = 1;x = x % mod;y=y%mod;while (y > 0)  {  if (y & 1)  res = ((res%mod)*(x%mod)) % mod;  
y = y>>1;x = ((x%mod)*(x%mod)) % mod;  }  return res%mod;  }  
  
ll l[3000][3000],r[3000][3000],u[3000][3000],d[3000][3000],A[3000][3000];
int main(){
    ll a,b;cin>>a>>b;
    for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
    	char c;cin>>c;
    	if(c=='#')A[i][j]=0;
    	else A[i][j]=1;
    }}
    
    
    
    /// left;
    for(int i=1;i<=a;i++)
    {
    	for(int j=1;j<=b;j++)
    	{
    		if(A[i][j]==0)l[i][j]=0;
    		else{
    			if(l[i][j-1]==0)l[i][j]=1;
    			else l[i][j]=1+l[i][j-1];}
    			
}}
    
    /// right
    for(int i=1;i<=a;i++)
    {
    	for(int j=b;j>=1;j--)
    	{
    		if(A[i][j]==0)r[i][j]=0;
    		else{
    			if(r[i][j+1]==0)r[i][j]=1;
    			else r[i][j]+=1+r[i][j+1];}
    	}
    }
    
    /// down
    for(int i=1;i<=b;i++)
    {
    	for(int j=1;j<=a;j++)
    	{
    		if(A[j][i]==0)d[j][i]=0;
    		else{
    			if(d[j-1][i]==0)d[j][i]=1;
    			else d[j][i]+=1+d[j-1][i];}
    	}
    }
    
    
    /// up
    for(int i=1;i<=b;i++)
    {
    	for(int j=a;j>=1;j--)
    	{
    		if(A[j][i]==0)u[j][i]=0;
    		else{
    			if(u[j+1][i]==0)u[j][i]=1;
    			else u[j][i]+=1+u[j+1][i];}
    	}
    }
    
    ll mx=0;
    
    for(int i=1;i<=a;i++)
    {
    	for(int j=1;j<=b;j++)
    	{
    		if(l[i][j]+r[i][j]+d[i][j]+u[i][j]-3>mx)mx=l[i][j]+r[i][j]+d[i][j]+u[i][j]-3;
    	}
    }
    cout<<mx<<endl;
    
}
    
    
   

    
