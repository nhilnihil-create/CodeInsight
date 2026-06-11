#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n=0;
	scanf("%d",&n);
	ll ans=0;
	for (int i=1;i<n;i++){
		ans+=(n-1)/i;
	}
	printf("%lld\n",ans);
	return 0;
}