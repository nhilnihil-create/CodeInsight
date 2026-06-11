#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector<int> era(int x)
{
	int search[x];
	int len = 0;
	vector<int> primes;
	search[0] = search[1] = 0;
	for (int i = 2; i < x; i++)
		search[i] = 1;
	double root_x = sqrt(x);
	for (int i = 0; ; i++) {
		int num = search[i];
		if (num == 1) {
			if (root_x <= i)
				break;
			else {
				primes.push_back(i); len++;
				for (int j = i; j < x; j+=i)
					search[j] = 0;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		if (search[i] == 1) {
			primes.push_back(i); len++;
			search[i] = 0;
		}
	}
	return primes;
}

int main(void) {

	vector<int> primes = era(1000000);

	while (1) {
		int a, d, n;
		cin >> a >> d >> n;
		if (a == 0 && d == 0 && n == 0) break;
		int count_primes = 0;
		int primes_now = 0;
		for (int i = a; i < 1000000; i+=d) {
			for (int j = primes_now; j < primes.size(); j++) {
				if (primes[j] == i) {
					count_primes++;
					primes_now = j;
					break;
				}
				else if (primes[j] > i) {
					primes_now = j;
					break;
				}
			} 
			if (count_primes == n) {
				cout << i << endl;
				break;
			} 
		}
	}
	return 0;
}

