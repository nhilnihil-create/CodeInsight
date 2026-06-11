#include<iostream>
#include<map>

using namespace std;

typedef long long ll;

int M;

int main() {
	cin >> M;
	ll sum = 0;
	ll cnt = 0;
	for (int i = 0; i < M; i++) {
		ll c, d;
		cin >> d >> c;
		sum += c * d;
		cnt += c;
	}
	ll ans = 0;
	ans += (cnt - 1);
	ans += (sum / 9);
	if (sum % 9 == 0)ans--;
	cout << ans << endl;
	return 0;
}