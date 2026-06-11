#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

template <class T>
void printArray(vector<T> arr) {for (T a: arr) cout << a << " ";cout << '\n';}
void printVerdict(bool verdict) {cout << (verdict ? "YES": "NO") << '\n';}
void printDecimal(double d) {printf("%.9f\n", d);}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<int> position;
	for (int i = 0; i<n; i++) {
		if (s[i] == 'A') position.push_back(i);
	}
	int cnt = 0;
	for (int pos: position) {
		if (!s.substr(pos, 3).compare("ABC")) cnt++;
	}
	cout << cnt << '\n';
}

