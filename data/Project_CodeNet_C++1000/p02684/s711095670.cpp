#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<ll> visit(n + 1, -1);
	int higePlusCycleLength = 0;
	int target = 0;
	while (visit[target] == -1) {
		visit[target] = higePlusCycleLength;
		higePlusCycleLength++;
		target = a[target];
	}
	int cycle = higePlusCycleLength - visit[target];
	int index = 0;
	if (k <= higePlusCycleLength) {		
		for (int i = 0; i < k; i++) {
			index = a[index];
		}
		cout << index + 1 << endl;
	}
	else {
		for (int i = 0; i < higePlusCycleLength; i++) {
			index = a[index];
		}
		k -= higePlusCycleLength;
		k %= cycle;
		for (int i = 0; i < k; i++) {
			index = a[index];
		}
		cout << index + 1 << endl;
	}
    return 0;
}