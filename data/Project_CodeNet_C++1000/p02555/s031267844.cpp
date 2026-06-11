#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e6+10;
int n;
ll f[maxn];
int main()
{
	cin>>n;
	f[0]=1;
	for (int i=3;i<=n;i++) f[i]=(f[i-3]+f[i-1])%mod;
	cout<<f[n]<<endl;
	return 0;
}

