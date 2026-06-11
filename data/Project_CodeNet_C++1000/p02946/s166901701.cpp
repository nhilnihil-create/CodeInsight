#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl "\n"
#define pb push_back

const int MAX = 10e5;

ll counter[MAX] = {0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, x;
	cin >> k >> x;
	for(int i = x - k + 1; i <= x + k - 1; i++) {
		cout << i << " ";
	}
}
