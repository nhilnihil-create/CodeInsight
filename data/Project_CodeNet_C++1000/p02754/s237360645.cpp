#include "bits/stdc++.h"

using namespace std;

int main() {
	long long N,A,B;
	cin >> N>>A>>B;
	long long ans = N / (A + B)*A;
	N %= A + B;
	if (N>A) {
		ans += A;
	}
	else {
		ans += N;
	}
	cout <<ans<<endl;
	return 0;
}