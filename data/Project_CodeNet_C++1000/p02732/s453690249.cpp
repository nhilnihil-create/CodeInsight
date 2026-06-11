#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n),cnt(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		--a[i];
		++cnt[a[i]];
	}
	long long int sm = 0;
	for(int i = 0; i < n; i++){
		sm += (1ll * cnt[i] * (cnt[i] - 1)) / 2;
	}
	for(int i = 0; i < n; i++){
		long long int tmp = 0;
		tmp -= (1ll * cnt[a[i]] * (cnt[a[i]] - 1)) / 2;
		--cnt[a[i]];
		tmp += (1ll * cnt[a[i]] * (cnt[a[i]] - 1)) / 2;
		++cnt[a[i]];
		cout << sm + tmp << "\n";
	}
	return 0;
}
