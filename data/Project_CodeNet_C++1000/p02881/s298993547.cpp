#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	cin >> N; 
	for (long long n = (long long)sqrt(N);n >= 1;--n) {
		if (0 == N%n) {
			cout <<  n + N/n- 2<<endl;
			return 0;
		}
	}
	return 0;
}
