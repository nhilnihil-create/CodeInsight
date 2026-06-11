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
	vector<int> pre(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '<') {
			pre[i] = (i > 0 ? pre[i - 1] + 1 : 1);
		}
		else {
			pre[i] = 0;
		}
	}
	vector<int> suf(n);
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '>') {
			suf[i] = (i < n - 1 ? suf[i + 1] + 1 : 1);
		}
		else {
			suf[i] = 0;
		}
	}
	ll ans = pre[n - 1] + suf[0];;
	for (int i = 0; i < n - 1; i++) {
		ans += max(pre[i], suf[i + 1]);
	}
	cout << ans;
}
