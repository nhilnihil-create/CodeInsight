#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll a, b;
	cin >> a >> b;
	if (a > 9 || b > 9)cout << -1 << endl;
	else cout << a * b << endl;
}
