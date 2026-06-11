#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],b[N];
signed main(){
	int n,sum=1,x;
	cin>>n;
	for(int i=0;i<=n;++i)
		cin>>a[i];
	for(int i=n;i>=0;--i)
		b[i]=b[i+1]+a[i];
	if(!n) return cout<<(a[0]==1?"1":"-1"),0;
	if(a[0]) return cout<<"-1",0;
	//cout<<1<<endl;
	int res=1;
	for(int i=1;i<=n;++i){
		res=min(res*2,b[i]);
		//cout<<res<<" "<<b[i]<<endl;
		if(res<a[i]) return cout<<"-1",0;
		sum+=res;res-=a[i];
	}
	cout<<sum;
	return 0;
}