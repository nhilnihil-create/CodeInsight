#include <iostream>

using namespace std;

unsigned long long *cache;

unsigned long long fun(int n) {
	if (cache[n] == -1) {
		cache[n] = fun(n-1) + fun(n-2);
	}
	return cache[n];
}

int main() {
	int n;
	cin >> n;
	cache = new unsigned long long[n+2];
	cache[0] = cache[1] = 1;
	for (int i = 2;i<n+2;i++) {
		cache[i] = -1;
	}
	fun(n);
	cout << cache[n] << endl;
	return 0;

}
