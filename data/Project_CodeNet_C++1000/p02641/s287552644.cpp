#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int x, n;
	scanf("%d%d", &x,&n);
	map<int, int> mp;
	for(int i=0; i<n; i++) {
		int q;
		scanf("%d", &q);
		mp[q] = 1;
	}
	int cek = 1e4;
	int ans = x;
	for(int i=-101; i<=101; i++) {
		if(mp[i]) continue;
		else if(abs(i-x) < cek) {
			cek = abs(x-i);
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}