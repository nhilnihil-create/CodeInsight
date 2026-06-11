#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
void printArray(vector<T> arr) {
	for (T a: arr) cout << a << " ";
	cout << '\n';
}

void printVerdict(bool verdict) {
	cout << (verdict ? "YES": "NO") << '\n';
}

void printDecimal(double d) {printf("%.9f\n", d);}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n; 
	int a[n];
	for (int i = 0; i<n; i++) cin >> a[i];
	int ret = 0;
	for (int i = 0; i<n-1; i++) {
		for (int j = i+1; j<n; j++) {
			ret += a[i] * a[j];
		}
	}
	cout << ret << '\n';
}

