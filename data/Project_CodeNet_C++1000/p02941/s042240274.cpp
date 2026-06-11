#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],b[200010];
int l[200010],r[200010];
int n;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			puts("-1");
			return 0;
		}
	}
	for(int i=2;i<=n;i++)l[i]=i-1;
	l[1]=n;
	for(int i=1;i<n;i++)r[i]=i+1;
	r[n]=1;
	int step=0;
	while(1){
		bool ok=1,ch=0;
		for(int i=1;i<=n;i++){
			if(a[i]==b[i])continue;
			if(a[i]>b[i]){
				puts("-1");
				return 0;
			}
			ok=0;
			int p=b[l[i]]+b[r[i]];
			if(b[i]-p<a[i])continue;
			step+=(b[i]-a[i])/p;
			b[i]-=(b[i]-a[i])/p*p;
			ch=1;
		}
		if(ok)break;
		if(!ch){
			puts("-1");
			return 0;
		}
	}
	cout<<step<<endl;
	return 0;
}
