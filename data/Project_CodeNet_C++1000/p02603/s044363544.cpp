#include<bits/stdc++.h>
using namespace std;
const int N=85;
typedef long long ll;
ll a[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int left=1,right=1;
	bool flag=0,flag2=1;
	ll money=1000,stock=0;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			if(flag==0){
				stock+=money/a[i-1];
				money%=a[i-1];
			}
			flag=1;
			right=i;
		}
		else if(a[i]<a[i-1]){
			if(flag==1){
				money+=stock*a[i-1];
				stock=0;
			}
			flag=0;
			left=i;
		}
		if(i==n) money+=stock*a[i],stock=0;
	}
	printf("%lld",money);
	return 0;
}
