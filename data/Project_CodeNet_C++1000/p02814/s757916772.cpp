#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

long long gcd(long long a, long long b){
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}


int main() {
	long long N, M;
	cin >> N >> M;

	vector<long long> A;
	rep(i, N) {
		long long num;
		cin >> num;
		A.push_back(num / 2);
	}
	// 重複要素の削除
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	long long a = 1;
	rep(i, A.size()) {
		a = lcm(a, A[i]);
	}

	rep(i, A.size()) {
		if ((a / A[i]) % 2 == 0) {
			cout << 0;
			return 0;
		}
	}
	long long ans = M / a;
	if (ans % 2 == 0)ans /= 2;
	else ans = (ans + 1) / 2;
	cout << ans;
	
}