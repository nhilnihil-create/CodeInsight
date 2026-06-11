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
	string s; cin >> s;
	int ret = 1;
	int ptr1 = 0;
	for (int i = 0; i<n; i++) {
		if (s[i] != s[ptr1]) {
			ret++;
			ptr1 = i;
 		}
	}
	cout << ret << '\n';
}

