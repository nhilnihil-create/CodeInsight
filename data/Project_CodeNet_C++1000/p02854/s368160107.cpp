#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int n;
	int a[200001];
	int sum[200001];

	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	sum[0] = a[0];
	for(int i=1;i<n;i++) sum[i] = sum[i-1] + a[i];

	ll ans = sum[n-1];
	for(int i=0;i<n;i++){
		ans = min(ans, abs(sum[n-1]-2*sum[i]));
	}

	printf("%lld\n",ans);

	return 0;
}
