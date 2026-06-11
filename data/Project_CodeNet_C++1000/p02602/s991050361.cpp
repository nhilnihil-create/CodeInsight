#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
const long long inf=0x3f3f3f3f;
long long a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=k+1;i<=n;i++)
	{
		long long j=i-k;
		if(a[i]>a[j])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}


