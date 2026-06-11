#include<iostream>
#include<cstdio>
#define LL long long
#define N 100010
using namespace std;

int main(){
	int n;LL d,c;
	LL sum=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d,&c);
		sum+=d*c;
		ans+=c;
	}
	ans+=sum/9-1;
	if(sum%9==0) ans--;
	cout<<ans;
	return 0;
}