#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define mod 1000000007
#define INF 1e18
#define MAX 1000007
typedef  long long ll;
int prime[MAX];
int main()
{
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// memset(prime,1,sizeof(prime));
	for (int i = 0; i < MAX; ++i)
		prime[i]=1;
	// cout<<prime[0]<<" ";
	for (int i = 2; i < MAX; ++i)
	{
		for (int j = i; j <MAX ; j+=i)
		{
			prime[j]++;
		}
	}
	int n;
	cin>>n;
	ll ans=0;
	for (int i = 1; i <n; ++i)
	{
		ans+=prime[n-i];
	}
	cout<<ans;
	return 0;
}