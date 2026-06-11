#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int a, b, c;

void solve() {
	cin >> a >> b >> c;
	if(a+b+c >= 22) cout << "bust";
	else cout << "win";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

