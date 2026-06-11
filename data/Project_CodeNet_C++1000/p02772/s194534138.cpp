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
	int N; cin >> N;
	vector<int> A(N); rep(i, N) cin >> A[i];
	rep(i, N) {
		if (A[i] % 2 == 1) continue;
		if (A[i] % 3 != 0 && A[i] % 5 != 0) {
			cout << "DENIED" << endl;
			return 0;
		}
	}
	cout << "APPROVED" << endl;
}