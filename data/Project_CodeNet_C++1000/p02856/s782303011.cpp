#include<iostream>
#include<cstdio>
#define maxn 200010
using namespace std;
int n;
long long d,c;
int main(){
	long long sum=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d,&c);
		sum+=d*c;
		ans+=c;
	}
	ans=ans+sum/9-1;
	if(sum%9==0)ans--;
	printf("%lld\n",ans);
	return 0;
}