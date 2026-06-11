#include <bits/stdc++.h>
using namespace std;

const int nax = 5e5+5;
vector<long long> ft(nax, 0);
int n;

int LSBOne(int x) {
	return x&(-x);
}

void modify(int p, int v) {
	//for(st[p+=n] += v;p>0;p>>=1) st[p>>1] = st[p] + st[p^1];
	for(int i = p; i <= n; i += LSBOne(i)) ft[i] += v; 
}

long long sum(int l) {
	long long ans = 0;
	for(int i = l; i > 0; i -= LSBOne(i)) ans += ft[i];
	return ans;
}

int main() {
	int q, a, b, t;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a;
      	modify(i+1, a);
	}
	//ft[0] = 0;
	//for(int i = 1; i < n; i++) ft[i] = ft[i-1] + arr[i];
	while(q--) {
		cin >> t >> a >> b;
		if(!t) {
			modify(a+1, b);
		}
		else cout << sum(b) - sum(a) << endl;
	}
	return 0;
}
