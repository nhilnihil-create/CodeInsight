#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int ans[10];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) ans[i] = -1;
	for (int i = 0; i < M; i++) {
		int s, c;
		cin >> s >> c;
		s--;
		if (ans[s] == -1) ans[s] = c;
		else if (ans[s] != c) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (N == 1 && ans[0] == -1) ans[0] = 0;
	else if (N != 1 && ans[0] == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (ans[i] == -1) {
			if (i == 0) ans[i] = 1;
			else ans[i] = 0;
		}
		cout << ans[i];
	}
	cout << endl;
}