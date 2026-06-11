#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}


int main() {
	int N, D;
	int Dw;
	cin >> N >> D;
	Dw = D * 2 + 1;
	if (N % Dw == 0)cout << N / Dw << endl;
	else cout << int(N / Dw) + 1 << endl;
	return 0;
}
