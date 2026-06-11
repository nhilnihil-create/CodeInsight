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

int D[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> D[i];
	if (D[0] != 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(D, D + N);
	ll ans = 1;
	int before = 1;
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		cnt++;
		if (D[i] == 0 || D[i] - D[i - 1] > 1) {
			cout << 0 << endl;
			return 0;
		}
		if (D[i] != D[i + 1]) {
			for (int j = 0; j < cnt; j++) {
				ans = (ans * before) % MOD;
			}
			before = cnt;
			cnt = 0;
		}
	}
	cout << ans << endl;
}
