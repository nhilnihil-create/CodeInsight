#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, A, B;
	cin >> N >> A >> B;
	long long a = N / (A + B);
	long long b = N % (A + B);
	long long total = 0;
	total += a * A;
	if (b <= A) {
		total += b;
	}
	else {
		total += A;
	}
	cout << total << endl;
}
