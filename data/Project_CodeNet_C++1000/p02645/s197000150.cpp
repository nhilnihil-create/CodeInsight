#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int N = 1e7 + 3;
vector<ll> temp(N, -1);

void sieve() {
	for (ll i = 2; i * i <= N; i++) {
		if (temp[i] == -1) {
			for (ll j = i * i; j <= N; j += i)temp[j] = i;
		}
	}
	return ;
}


void solve() {
	string s; cin >> s;
	cout << s.substr(0, 3);



}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t;
	// while (t--)
	solve();

}