//sppsfver - 20.08.2020
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;
const int MAX = 1e6+5;

ll n;
ll arr[MAX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	arr[1] = 7%n;
	if (n == 7 || n == 1) return cout << 1 << endl, 0;
	for (int i = 2; i <= n; i++){
		arr[i] = arr[i-1]*10+7;
		arr[i] %= n;
		if (arr[i] == 0) return cout << i << endl, 0;
	}
	cout << -1 << endl;

	return 0;
}
