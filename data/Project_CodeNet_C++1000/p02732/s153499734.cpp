#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

ll A[200001];
ll s[200001];

int main() {
	int N; cin >> N;
	rep(i, N) {
		int tmp; cin >> tmp;
		A[i] = tmp;
		s[tmp]++;
	}
	ll a = 0;
	rep(i, N+1) {
		if (s[i] < 2) continue;
		a += s[i]*(s[i]-1)/2;
	}
	rep(i, N) {
		ll ans = a;
		if (s[A[i]] <= 1) {
			cout << ans << endl;
		} else if (s[A[i]] == 2) {
			cout << ans - 1 << endl;
		} else {
			ans -= s[A[i]]*(s[A[i]]-1)/2;
			ans += (s[A[i]]-1)*(s[A[i]]-2)/2;
			cout << ans << endl;
		}
	}
}