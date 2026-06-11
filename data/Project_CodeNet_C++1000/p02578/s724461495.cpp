#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int& x : v)
		scanf("%d",&x);
	int k = v[0];
	long long ans = 0;
	for(int i = 1; i < n; i++){
		if(v[i] > k)
			k = v[i];
		else
			ans += k-v[i];
	}
	printf("%lld\n", ans);
	return 0;
}