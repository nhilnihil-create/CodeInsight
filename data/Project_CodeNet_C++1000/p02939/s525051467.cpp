#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int ans = 1;
	string prv = s.substr(0, 1);
	for (int i = 1; i < n; i++) {
		if (s.substr(i, 1) != prv) {
			ans++;
			prv = s.substr(i, 1);
		}
		else if(s.substr(i, 2) != prv) {
			ans++;
			prv = s.substr(i, 2);
			i += 1;
		}
	}
	cout << ans;
}
