#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	cout << string(max(a, b), min(a, b) + '0');
}