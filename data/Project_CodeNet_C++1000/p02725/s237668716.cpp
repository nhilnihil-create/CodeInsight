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
	int K, N; cin >> K >> N;
	vector<int> v;
	for (int ii = 0; ii < N; ii++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int ans = K;
	for (int ii = 0; ii < N; ii++) {
		int tmp;
		if (ii != N - 1) {
			tmp = K - (v[ii + 1] - v[ii]);
		} else {
			tmp = v[ii] - v[0];
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}