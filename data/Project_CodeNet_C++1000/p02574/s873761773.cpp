#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define deb(x) cout << #x << " = "<< x << "\n";

const int maxn = 1000002;
int n, a[maxn+4], b[maxn];
int cnt[maxn+4];
vector<int> p;

signed main() {
	//freopen("in.txt", "r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	fill(a, a+maxn, 1);
	
	for(int i = 2; i*i <= maxn; i++) {
		if(a[i] == 0) continue;
		for(int j = i*i; j <= maxn; j += i)
			a[j] = 0;
	}
	for(int i = 2; i <= maxn; i++) {
		if(a[i] == 1)
			p.push_back(i);
	}

	bool pairwise_coprime = true;
	
	for(int i = 0; i < n; i++) {
		int num = b[i];
		for(int j = 0; p[j]*p[j] <= num; j++) {
			if(num % p[j] == 0) {
				cnt[p[j]]++;
			} else continue;
			if(cnt[p[j]] > 1) {
				pairwise_coprime = false;
				break;
			}
			while(num % p[j] == 0) {
				num /= p[j];
			}
		}
		if(num > 1) cnt[num]++;
		if(cnt[num] > 1) pairwise_coprime = false;
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
