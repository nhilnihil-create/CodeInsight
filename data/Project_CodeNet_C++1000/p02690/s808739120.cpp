#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
long long power5(long long n) {
	return n * n * n * n * n;
}
int main() {
	long long x; cin >> x;
	for (long long i = -1000; i < 1000; i++) {
		for (long long j = -1000; j < 1000; j++) {
			if (power5(i) - power5(j) == x) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
}