#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	ll left = 0, right = A[N - 1] + 1;
	ll centre, ans;
	while(right - left > 1) {
		centre = (left + right) / 2;
		ll cnt = 0;
		for(int i = 0; i < N; i++) cnt += ceil((double)A[i] / (double)centre) - 1;
		if(cnt > K) left = centre;
		else {
			ans = centre;
			right = centre;
		}
	}
	cout << ans << endl;
	return 0;
}