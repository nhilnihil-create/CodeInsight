#include<iostream>
#include<algorithm>
#include<queue>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int N,M;
ll a[maxn];

int main()
{
	ios;
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>a[i];
	ll ans=a[0];
	for(int i=1;i<N;i++) 
		ans=ans*a[i]/__gcd(ans,a[i]);
	for(int i=0;i<N;i++)
	{
		if((ans/a[i])%2==0)
		{
			cout<<0;
			return 0;		
		}
	}
	cout<<((M*2/ans+1)/2);
	return 0;	
}