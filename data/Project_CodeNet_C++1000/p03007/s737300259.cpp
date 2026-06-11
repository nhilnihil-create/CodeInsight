#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n;
long long a[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1,greater<long long>());
	int st=n;
	for(int i=2;i<=n;i++) if(a[i]<0) {st=i;break;}
	long long ans=0;
	for(int i=1;i<st;i++) ans+=a[i];
	for(int i=st;i<=n;i++) ans-=a[i];
	cout<<ans<<endl;
	for(int i=2;i<st;i++) cout<<a[st]<<' '<<a[i]<<endl,a[st]-=a[i];
	for(int i=st;i<=n;i++) cout<<a[1]<<' '<<a[i]<<endl,a[1]-=a[i];
	return 0;
}