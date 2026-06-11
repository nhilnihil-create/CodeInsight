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
	int k;
	cin >> k;
	int l = 1;
	while(l < n && s[l] == s[l - 1])
		l++;
	int r = n - 2;
	while(r >= 0 && s[r] == s[r + 1])
		r--;
	if (l == n) {
		cout << (1LL * n * k) / 2;
		return 0;
	}
	int pre = l;
	int suf = n - r - 1;
	int midAns = 0;
	int c = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] != s[i - 1]) {
			midAns += c / 2;
			c = 1;
		}
		else {
			c++;
		}
	}
	midAns += c / 2;
	if (s[0] != s[n - 1]) {
		ll ansForOne = pre / 2 + midAns + suf / 2;
		cout << (1LL * ansForOne * k);
	}
	else {
		ll totalAns = pre / 2 + 1LL * midAns * k + 1LL * ((pre + suf) / 2) * (k - 1) + suf / 2;
		cout << totalAns;
	}
}

