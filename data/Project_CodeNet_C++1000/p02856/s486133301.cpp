#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
const int maxn=2e5+7;
ll a[maxn],b[maxn];
int main()
{
	scanf("%d",&m);ll ans=0;ll sum=0;ll c=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		sum+=a[i]*b[i];c+=b[i];
	}
	cout<<(c-1)+((sum-1)/9)<<endl;
 } 