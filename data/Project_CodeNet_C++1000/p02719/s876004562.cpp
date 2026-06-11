#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100;
const int INF = 1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	ll N, K; cin >> N >> K;
	ll tmp1 = N % K;
	ll tmp2 = tmp1 - K;
	if ( tmp2 < 0 ) {
		tmp2 = tmp2 * (-1);
	}
	ll ans = min(tmp1, tmp2);
	cout << ans << endl;
}