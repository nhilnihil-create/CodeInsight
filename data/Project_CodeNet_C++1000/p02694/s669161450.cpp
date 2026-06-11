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

	ll x;
	cin >> x;

	ll y = 100, cnt = 0;

	while (y < x) {
		y = y + y / 100;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}