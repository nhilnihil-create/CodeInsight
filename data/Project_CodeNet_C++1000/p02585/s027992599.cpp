#include<bits/stdc++.h>
using namespace std;
int p[5005],c[5005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
	}
	for(int i=0;i<n;i++)
	cin>>c[i];
	long long ans=-1e18;
	for(int i=0;i<n;i++)
	{
		int now=i;
		long long cs=0;
		long long cc=0;
		while(true){
			cc++;
			cs+=c[now];
			now=p[now];
			if(now==i)
			break;
		}
		long long path=0;
		int cnt=0;
		while(true){
			cnt++;
			path+=c[now];
			if(cnt>k)
			break;
			int num=(k-cnt)/cc;
			long long score=path+max(0LL,cs)*num;
			ans=max(ans,score);
			now=p[now];
			if(now==i)
			break;
		}
	}
	cout<<ans<<endl;
}