#include<bits/stdc++.h>
#define me memset
const int N=1e6+10;
const int mod=1e9+7;
using namespace std;
int k;
long long q[N],hh=1,tt=0;
int main(){
	scanf("%d",&k);
	if(k<=12){
		printf("%d\n",k);
		return 0;
	}
	for(int i=1;i<=9;++i) q[++tt]=i;
	int cnt=0;
	long long ans;
	while(cnt!=k){
		long long now=q[hh];
		hh++;
		long long res=now%10;
		if(res!=0)q[++tt]=now*10+res-1,cnt++;
		if(cnt==k-10+1){
		   ans=q[tt];
		   break;
		}
		q[++tt]=now*10+res,cnt++;
		if(cnt==k-10+1){
			ans=q[tt];
			break;
		}
		if(res!=9)q[++tt]=now*10+res+1,cnt++;
		if(cnt==k-10+1){
			ans=q[tt];
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}