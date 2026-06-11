#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define deb(x) cout << #x << " = "<< x << "\n";

const int maxn = 1000000;
int n, a[maxn+1], b[maxn+1];

signed main() {
//	freopen("in.txt", "r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		a[b[i]]++;
	}
	bool pairwise_coprime = true;
	for(int i = 2; i <= maxn; i++) {
		int cnt = 0;
		for(int j = i; j <= maxn; j += i) { 
			cnt += a[j];
			if(cnt >= 2) {
				pairwise_coprime = false;
				break;	
			}
		}
		if(!pairwise_coprime) break;
	}
	
	if(pairwise_coprime) {
		cout << "pairwise coprime";
		return 0;
	}
	
	int g = 0;
	for(int i = 0; i < n; i++) {
		g = __gcd(g, b[i]);
		if(g == 1) break;
	}
	if(g == 1) {
		cout << "setwise coprime";
	} else {
		cout << "not coprime";
	}
}
