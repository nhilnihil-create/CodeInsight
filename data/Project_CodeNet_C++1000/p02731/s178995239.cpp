#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

double l;

void solve() {
	cin >> l;
	cout << fixed << setprecision(8) << pow(l/3.0, 3) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

