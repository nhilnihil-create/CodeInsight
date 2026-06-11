#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  2進数ならば baseNumber を  2 とする
// 10進数ならば baseNumber を 10 とする
ll GetDigitsCount(ll targetNumber, ll baseNumber) {
	ll digitsCount = 0;
	while (targetNumber != 0) {
		digitsCount++;
		targetNumber /= baseNumber;
	}
	return digitsCount;
}

int main() {

	ll n, k; cin >> n >> k;
	cout << GetDigitsCount(n, k) << endl;
    return 0;
}