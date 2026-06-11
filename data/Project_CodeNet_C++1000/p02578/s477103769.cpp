#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n; scanf("%d", &n);
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	ll ans = 0, num = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] >= num) num = a[i];
		else ans += (num - a[i]); 
	}
	printf("%lld\n", ans);
}