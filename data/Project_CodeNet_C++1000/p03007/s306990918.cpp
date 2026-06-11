#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int main(){
//	freopen("01.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,tmp=0;
	a[0]=-1e9;
	for(int i=1;i<=n;++i)
		if(a[i]>=0 && a[i-1]<=0){
			tmp=i;break;
		}
	if(tmp==0){
		int ans=a[n];
		for(int i=1;i<n;++i)
			ans-=a[i];
		cout<<ans<<endl;
		int res=a[n];
		for(int i=1;i<n;++i)
			cout<<res<<" "<<a[i]<<endl,res-=a[i];
		return 0;
	}
	tmp=max(tmp,2);
	for(int i=1;i<tmp;++i)
		ans-=a[i];
	for(int i=tmp;i<=n;++i)
		ans+=a[i];
	cout<<ans<<endl;
	int res=a[1];
	for(int i=tmp+1;i<=n;++i)
		cout<<res<<" "<<a[i]<<endl,
		res-=a[i];
	cout<<a[tmp]<<" "<<res<<endl;
	res=a[tmp]-res;
	for(int i=2;i<tmp;++i)
		cout<<res<<" "<<a[i]<<endl,
		res-=a[i];
	return 0;
}