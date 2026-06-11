#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

const ll INF = 2e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int N, M, V, P, A[MAXN];

bool chk(int idx) {
	int x = A[idx], a = idx - 1;
	if(V-P-a <= 0) return (x + M >= A[N-P+1]);
	if(A[N-P+1] > x + M) return 0;
	ll sum = 0;
	for(int i=idx+1; i<=N-P+1; i++) sum += x + M - A[i];
	return (sum >= 1LL * (V-P-a) * M);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> V >> P;
	for(int i=1; i<=N; i++) cin >> A[i];
	sort(A+1, A+1+N);

	int l = 1, r = N - P, ans = P;
	while(l <= r) {
		int mid = l + r >> 1;
		if(chk(mid)) {
			r = mid - 1;
			ans = N - mid + 1;
		}
		else l = mid + 1;
	}

	cout << ans;
}