#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO;
	
	int x, n;
	cin >> x >> n;
	set<int> ar;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ar.insert(a);
	}
	if (n == 0) {
		cout << x;
		return 0;
	}
	pair<int, int> sm = {-1, -1};
	for (int i = x; i >= 0; --i) {
		if (!ar.count(i)) {
			sm.first = abs(x - i);
			sm.second = i;
			break;
		}
	}
	
	for (int i = x; true; ++i) {
		if (!ar.count(i)) {
			if (abs(x-i) < sm.first) {
				sm.second = i;
			}
			break;
		}
	}
	
	cout << sm.second;
}	
