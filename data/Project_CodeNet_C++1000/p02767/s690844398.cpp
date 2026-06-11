#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)

int main() {
	int N, X[100]; cin >> N;
	int sum = 0;
	rep(i, N) {
		cin >> X[i];
		sum += X[i];
	}
	int mid = sum / N;
	int ans = 0;
	rep(i, N) ans += (X[i] - mid) * (X[i] - mid);
	for (int i = 1; i <= sum % N; i++) {
		int tmp = 0;
		rep(j, N) tmp += (X[j] - (mid+i)) * (X[j] - (mid+i));
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}