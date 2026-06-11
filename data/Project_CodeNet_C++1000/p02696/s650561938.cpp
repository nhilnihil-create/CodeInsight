#include "bits/stdc++.h"
using namespace std;

int main() {
	long long A,B,N;
	cin >> A>>B>>N;
	//xは0 kara B-1 までみればいい
	long long m = min(N,B-1);
	long long ans = m * A / B;
	cout << ans << endl;
	return 0;
}