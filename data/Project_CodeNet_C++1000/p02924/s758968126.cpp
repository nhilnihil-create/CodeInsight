#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	N--;
	ll ans = N * (N + 1) / 2;
	cout << ans << endl;
	return 0;
}