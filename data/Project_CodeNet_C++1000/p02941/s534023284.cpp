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
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> B(n);
	set<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		st.insert({B[i], i});
	}
	ll ans = 0;
	while(!st.empty()) {
		auto it = prev(st.end());
		if (A[it->ss] == B[it->ss]) {
			st.erase(it);
		}
		else {
			int i = it->ss;
			int val = B[i] - (B[(i + 1) % n] + B[(i - 1 + n) % n]);
			if (val < A[i]) {
				cout << -1;
				return 0;
			}
			else {
				int mx = max(B[(i + 1) % n], B[(i - 1 + n) % n]);
				int sum = (B[(i + 1) % n] + B[(i - 1 + n) % n]);
				ans += max(1, ((B[i] - max(A[i], mx)) / sum));
				B[i] -= max(sum, ((B[i] - max(A[i], mx)) / sum) * sum);
				st.insert({B[i], i});
				st.erase(it);
			}
		}
	}
	cout << ans;
}
