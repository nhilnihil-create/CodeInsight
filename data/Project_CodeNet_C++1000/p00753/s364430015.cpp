#include<iostream>

using namespace std;

bool is_prime[246912];
bool is_prime_small[497];

void segment_sieve(long long a, long long b) {
	for(int i = 0; (long long)i * i < b; i++) { is_prime_small[i] = true; }
	for(int i = 0; i < b - a; i++) { is_prime[i] = true; }
	for(int i = 2; (long long)i * i < b; i++) {
		if(is_prime_small[i]) {
			for(int j = 2 * i; (long long)j * j < b; j += i) { is_prime_small[j] = false; }
			for(long long j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) { is_prime[j - a] = false; }
		}
	}
}

int main(void) {
	int in, count;
	int i;

	segment_sieve(1, 246912);

	while(true) {
		cin >> in;
		if(in == 0) { break; }
		count = 0;
		for(i = in; i < 2 * in; i++) {
			if(is_prime[i]) { count++; }
		}
		cout << count << endl;
	}

	return 0;
}