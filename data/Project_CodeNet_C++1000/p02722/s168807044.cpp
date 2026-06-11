#include<bits/stdc++.h>
#define int long long
#define puts(x) cout << x << "\n"
#define endwith return
using namespace std;
set<int>ans;
signed main() {
	int n; cin >> n;
	if (n == 2) { puts(1); endwith 0; }
	ans.insert(n - 1);
	ans.insert(n);
	for (int i = 2; i <= sqrt(n); i++) {
		if ((n - 1) % i == 0) { ans.insert(i); ans.insert((n - 1) / i); }
		else if (n % i == 0) {
			int n1 = n;
			while (n1 % i == 0)n1 /= i;
			while (n1 > i)n1 %= i;
			if (n1 == 1)ans.insert(i);
			n1 = n;
			while (n1 % (n / i) == 0)n1 /= (n / i);
			while (n1 > (n / i))n1 %= (n / i);
			if (n1 == 1)ans.insert((n / i));
		}
	}
	puts(ans.size());
}