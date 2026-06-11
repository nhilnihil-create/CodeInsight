#include <cstdio>
#include <algorithm>
using ll = long long;
using namespace std;
int main(){
	ll n,k;scanf("%lld %lld",&n,&k);
	ll arr[n];
	for(ll i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
	sort(arr,arr+n);
	ll total(0);
	for(ll i=0;i<=n-1-k;i++){
			total += arr[i];
		}
	printf("%lld",total);	
	return 0;
	}
