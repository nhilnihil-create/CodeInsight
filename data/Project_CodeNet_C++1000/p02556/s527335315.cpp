#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;



void solve()
{		
	int n,x,y;
	cin>>n;
	vector<int> tmp(1ll<<2,-inf);
	int ans=-inf;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=0;j<(1ll<<2);j++)
		{
			if(tmp[j]==-inf)
				break;
			int z=tmp[j];
			if(j&1)
				z-=y;
			else
				z+=y;
			if((j>>1)&1)
				z-=x;
			else
				z+=x;
			ans=max(ans,z);
		}

		for(int j=0;j<(1ll<<2);j++)
		{
			int z=0;
			if(j&1)
				z+=y;
			else
				z-=y;
			if((j>>1)&1)
				z+=x;
			else
				z-=x;
			tmp[j]=max(tmp[j],z);
			//cout<<tmp[j]<<endl;
		}
	}   
	cout<<ans<<endl;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
 //cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}