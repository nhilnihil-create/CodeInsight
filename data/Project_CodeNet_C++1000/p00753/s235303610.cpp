#include<iostream>
#include<cstring>
using namespace std;

bool is_prime[300000];

int sieve(int a) {
	int p = 0,p1=0;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= a * 2; i++) {
		if (i == a+1)p1 = p;
		if (is_prime[i]) {
			p++;
			for (int j = i * 2; j <= a * 2; j += i)is_prime[j] = false;
		}
	}
	return p - p1;
}

int main() {
	int n;
	memset(is_prime, true, 300000);
	while (cin >> n, n) {
		cout << sieve(n) << endl;
	}
}