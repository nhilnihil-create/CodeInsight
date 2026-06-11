#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int isp[300000], cnt[300000];

int main() {
	memset(cnt, 0, sizeof(cnt));
	memset(isp, 0, sizeof(isp));
	
	for_(i,2,300000) {
		if (isp[i] == 0) {
			++cnt[i];
			for (int j = 2 * i; j < 300000; j += i) isp[j] = 1;
		}
		
		cnt[i] += cnt[i - 1];
	}
	
	int n;
	
	while (cin >> n, n) {
		cout << cnt[2 * n] - cnt[n] << endl;
	}
}