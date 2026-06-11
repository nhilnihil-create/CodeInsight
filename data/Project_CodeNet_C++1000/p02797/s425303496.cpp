#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e9;
ll n, m, sum;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> sum;
	for (int i = 0;i < m;i++)
		cout << sum << " ";
	if (sum < inf) {
		for (int i = m;i < n;i++)
			cout << inf << " ";
	}
	else {
		for (int i = m;i < n;i++)
			cout << inf - 1 << " ";
	}
}