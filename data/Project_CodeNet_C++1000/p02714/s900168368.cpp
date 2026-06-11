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

int r[4010], g[4010], b[4010];
int main()
{
	int N;
	string S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		r[i + 1] = r[i];
		g[i + 1] = g[i];
		b[i + 1] = b[i];
		if (S[i] == 'R') r[i + 1]++;
		if (S[i] == 'G') g[i + 1]++;
		if (S[i] == 'B') b[i + 1]++;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (S[i] == S[j]) continue;
			int diff = j - i;
			if ((S[i] == 'R' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'R')) {
				ans += b[N] - b[j + 1];
				if (S[min(j + diff, N)] == 'B') ans--;
			}
			else if ((S[i] == 'B' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'B')) {
				ans += r[N] - r[j + 1];
				if (S[min(j + diff, N)] == 'R') ans--;
			}
			else {
				ans += g[N] - g[j + 1];
				if (S[min(j + diff, N)] == 'G') ans--;
			}
		}
	}
	cout << ans << endl;
}