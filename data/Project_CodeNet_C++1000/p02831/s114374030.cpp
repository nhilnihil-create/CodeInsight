#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 2つの整数の場合
long long GetLeastCommonMultiple(long long a, long long b) {
	long long m = a;
	long long n = b;
	long long temp;
	while (m % n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return a / n * b;
}

int main() {

    ll a, b; cin >> a >> b;
	cout << GetLeastCommonMultiple(a, b) << endl;
    return 0;
}