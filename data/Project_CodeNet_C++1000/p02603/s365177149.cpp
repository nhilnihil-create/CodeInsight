#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[85];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll money=1000,stock=0;
	for(int i=1;i<=n-1;i++){
		stock=0;
		if(a[i]<a[i+1]) stock=money/a[i];
		money+=(a[i+1]-a[i])*stock;
	}
	printf("%lld",money);
	return 0;
}