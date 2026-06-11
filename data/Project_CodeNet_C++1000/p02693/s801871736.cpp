#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k, a, b; cin >> k >> a >> b;
	int temp = k * (a/k + (a%k != 0));
	if (temp >= a && temp <= b) cout << "OK" << '\n';
	else cout << "NG" << '\n';
}