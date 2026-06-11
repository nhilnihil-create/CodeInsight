#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c,k;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
	long long ans = min(a,k);
	k -= a;
	k = k-b;
	if(k > 0){
		ans -= k;
	}
	printf("%lld\n", ans);
	return 0;
}