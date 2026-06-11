#include<bits/stdc++.h>
#define NN 1000007
bool is_prime[NN];
std::vector<int>primes;
int gcd(int a, int b){	
	return !a?b: gcd(b % a, a);
}
void sieve() {
	for (int x = 2; x < NN; x++) {
		if (!is_prime[x]) {
			primes.push_back(x);
			for (int z = x + x; z < NN; z += x) {
				is_prime[z] = 1;
			}
		}
	}
}
std::set<int> factors(int number){
	std::set<int>fa;
	int q = 0;
	int f = primes[q];
	while (f * f <= number) {
		while (number % f == 0) {
			fa.insert(f);
			number /= f;
		}
		f = primes[++q];
	}
	if (number != 1)fa.insert(number);

	return fa;
}
int main() {
	sieve();
	int num; std::cin >> num;
	std::vector<int>arr;
	for (int x = 0; x < num; x++) {
		int l; std::cin >> l;
		arr.push_back(l);
	}
	std::map<int, int>mp;
	for (auto x : arr) {
		std::set<int>st = factors(x);
		for (auto z : st) mp[z]++;
	}
	bool tr = true;
	for (auto x : mp) {
		if (x.second > 1) { tr = false; break; }
	}
	if (tr) {
		std::cout << "pairwise coprime";
		return 0;
	}
	int secondPlane = arr[0];
	for (int x = 1; x < num; x++) {
		secondPlane = gcd(secondPlane, arr[x]);
	}
	if (secondPlane == 1)std::cout << "setwise coprime";
	else {
		std::cout << "not coprime";
	}


}

