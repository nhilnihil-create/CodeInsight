#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int main() {

	int k, a, b;
	cin >> k >> a >> b;

	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}

	cout << "NG" << endl;

	return 0;
}