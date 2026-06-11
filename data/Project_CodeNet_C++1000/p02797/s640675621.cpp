#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define puts(x) cout << x << "\n"
using namespace std;
signed main() {
	int n, k, s; cin >> n >> k >> s;
	for0(i, n) {
		if (i)cout << ' ';
		if (i < k)cout << s;
		else cout << (s + 1) % 1000000000;
	}puts("");
}