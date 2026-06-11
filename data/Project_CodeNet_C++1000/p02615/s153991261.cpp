#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,arr[200005],has,f[200005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1,greater<int>());
	f[0]=1,f[1]=1;
	for(int i=2;i<=n;i++) f[i]=2;
	int p=2,now=1;
	while(p<=n)
	{
		if(f[now]==0) now++;
		has+=arr[now];
		f[now]--;
		p++;
	}
	cout<<has<<endl;
}