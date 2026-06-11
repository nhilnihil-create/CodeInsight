#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	io_init;
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	vector<int> ans;
	for (int i = N; i > 0; ) {
		bool flag = false;
		for (int j = max(i - M, 0); j < i; j++) {
			if (S[j] == '0') {
				ans.push_back(i - j);
				i = j;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}