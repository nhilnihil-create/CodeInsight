#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cout << "ACL";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		//cout << endl;
	}
}