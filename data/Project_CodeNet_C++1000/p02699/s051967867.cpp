#include <bits/stdc++.h>
using namespace std;
template<class T> bool chmax(T& a,T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a,T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	int s, w;
	cin >> s >> w;
	if (s <= w) cout << "unsafe" << '\n';
	else cout << "safe" << endl;
}