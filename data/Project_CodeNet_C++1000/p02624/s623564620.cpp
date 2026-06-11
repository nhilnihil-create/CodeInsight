#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll f[N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i) f[j]++;//逆向思维
	ll ans=0;
	for(ll i=1;i<=n;i++) ans=ans+f[i]*i;
	cout<<ans<<endl;
 } 