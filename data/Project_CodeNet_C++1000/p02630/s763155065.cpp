#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long n, q;
	long long sum = 0;
	cin >> n;
	vector<long long> A(n);
	unordered_map<long long, long long> freq;
	for (long long i = 0; i < n; i++) {
		cin >> A[i];
		freq[A[i]]++;
		sum += A[i];
	}
	cin >> q;
	while (q--) {
		long long a, b;
		cin >> a >> b;
		sum -= (a -	 b) * freq[a];
		freq[b] += freq[a];
		freq[a] = 0;
		cout << sum << endl;
	}

}
