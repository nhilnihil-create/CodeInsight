#include <bits/stdc++.h>

using ll = long long;
constexpr ll INF = 1000000000;
constexpr ll mod = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }

using namespace std;

//fixed << setprecision(10)

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int n;
	cin >> n;

	vector<string>s(n);
	for(int i = 0; i < n; i++)cin >> s[i];

	map<string, int>seq;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (seq[s[i]] == 0) {
			seq[s[i]]++;
			cnt++;
		}
	}

	cout << cnt << endl;
}