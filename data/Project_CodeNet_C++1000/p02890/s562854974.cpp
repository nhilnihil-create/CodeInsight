#include <bits/stdc++.h>
using namespace std;

#define MAXN 300*1000 + 5

using ll = long long;

ll freq[MAXN], freq_freq[MAXN];

ll f(int x) {
	ll res = x * (freq_freq[MAXN-1] - freq_freq[x]) + freq[x];
	return res / x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		freq[x]++;
	}
	
	for(int i = 0; i < MAXN; i++) {
		if(freq[i] == 0) continue;
		freq_freq[freq[i]]++;
	}
	
	for(int i = 1; i <= n; i++) {
		freq[i] = freq[i-1] + 1LL * i * freq_freq[i];
	}
	
	partial_sum(freq_freq, freq_freq + MAXN, freq_freq);
	//$ for(int i = 1; i <= n; i++) {
		//$ cerr << i << ' ' << f(i) << endl;
	//$ }
	
	//$ return 0;
	
	for(int k = 1; k <= n; k++) {
		int lo = 0, hi = n+1;
		while(lo < hi) {
			int x = lo + (hi-lo+1)/2;
			if(k <= f(x)) {
				lo = x;
			} else {
				hi = x-1;
			}
		}
		
		cout << lo << '\n';
	}
	
}
