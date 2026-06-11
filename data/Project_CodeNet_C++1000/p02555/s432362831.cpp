#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll f[2006];
int main()
{
	ios;
	f[0]=1;
	for(int i=3;i<=2000;++i)
		for(int j=3;j<=i;++j)
		{
			f[i]=(f[i]+f[i-j])%mod;
		}
	int s;
	cin>>s;
	cout<<f[s]<<'\n';
}