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
	int N, K; cin >> N >> K;
	vector<int> v(N);
	ll sum = 0;
	rep(i, N) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= min((int)(v.size()), K); i++) {
		sum -= v[v.size()-i];
	}
	cout << sum << endl;
}