#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
const long long inf=0x3f3f3f3f;
long long ans,u[maxn],v[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<n;i++)
		cin>>u[i]>>v[i];
	for(long long i=1;i<=n;i++)
		ans+=i*(n-i+1);
	for(long long i=1;i<=n-1;i++)
	{
		if(u[i]>v[i])
			swap(u[i],v[i]);
		ans-=u[i]*(n-v[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}


