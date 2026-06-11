#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<vector>
#include<cstring>
#include<utility>
#include<set>
#include<map>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 2e9
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const double PI = acos(-1);

using namespace std;
ll A[200001];
ll B[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//	freopen("input.txt", "r", stdin);
	
	ll N, M, K; cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	
	ll val = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (val + A[i] <= K) {
			val += A[i];
			cnt++;
		}
		else break;
	}
	int idx = cnt;
	int s = 1;
	for (int i = 1; i <= M; i++) {
		if (val + B[i] <= K) {
			val += B[i];
			cnt++;
			s = i+1;
		}
		else break;
	}
	ans = max(ans, cnt);

	while (idx >= 1 && s <=M) {
		val -= A[idx--];
		cnt--;
		while (val + B[s] <= K && s<=M) {
			val += B[s++];
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}
