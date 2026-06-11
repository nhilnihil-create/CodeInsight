#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include<functional>
#include<queue>
#include<regex>
#include<time.h>
#include<type_traits>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll INF = 1050000000;
constexpr ll LONGINF = 1050000000000000000;


int main() {
	int n; cin >> n;
	vector<ll> a(n), b(n);
	priority_queue<pair<ll, int>> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		q.push({ b[i],i });
	}

	ll ans = 0;
	bool flag = true;

	while (!q.empty()) {
		ll key = q.top().first;
		int i = q.top().second;
		q.pop();

		if (a[i] == key) {//値が同じなら終了
			
		}
		else {
			if (a[i] > key) {//処理する値がそれ未満なら、不可能
				flag = false;
				break;
			}
			else {//a[i]<keyの時

				ll s = (b[(i - 1 + n) % n] + b[(i + 1) % n]);
				ll t = b[i] - a[i];

				ans += t / s;

				if ((t / s) == 0) {
					flag = false;
					break;
				}

				key -= (t / s) * s;
				b[i] = key;
				q.push({ key,i });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			flag = false;
			break;
		}
	}


	
	if (flag) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}