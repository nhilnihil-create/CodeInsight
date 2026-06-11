#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;

ll N;

int main() {
	cin >> N;
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += i * (N + 1 - i);
	}
	for (int i = 0; i < N - 1; i++) {
		ll b, e;
		cin >> b >> e;
		if (b > e)swap(b, e);
		ans -= (N + 1 - e) * b;
	}
	cout << ans << endl;
	return 0;
}