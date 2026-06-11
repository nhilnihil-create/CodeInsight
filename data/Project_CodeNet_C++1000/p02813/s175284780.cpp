#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll p[10];
ll q[10];
ll index[10];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}

	for (int i = 0; i < n; i++) {
		index[i] = i + 1;
	}
	int x, y;
		int count = 1;
	do {
		int check = 0;
		int check2 = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] == index[i]) {
				check++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (q[i] == index[i]) {
				check2++;
			}
		}
		if (check == n) {
			x = count;
		}
		if (check2 == n) {
			y = count;
		}

		count++;
	} while (next_permutation(index, index + n));
	cout << abs(x - y) << endl;
	return 0;
}
