#include <iostream>
#include <vector>
#include <string>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int main() {
  std::vector<bool> sieve (1001, true);
  for (int i=2; i<=1000; i++) {
	if (sieve[i]) {
	  for (int j=i*i; j<=1000; j+=i) {
		sieve[j] = false;
	  }
	}
  }
  vector primes;
  for (int i=2; i<=1000; i++)
	if (sieve[i])
	  primes.push_back(i);
  // 168 Primes are there

  int n; input >> n;
  vector freqs (1000001, 0);
  for (int i=0; i<n; i++) {
	int num; input >> num;
	for (int p=0; p<primes.size(); p++) {
	  int prime = primes[p];
	  if (prime > num)
		break;
	  if (num % prime == 0)
		freqs[prime] ++;
	  while (num % prime == 0)
		num /= prime;
	}
	if (num > 1)
	  freqs[num] ++;
  }
  bool pairwise = false, setwise = false;
  for (int freq : freqs) {
	if (freq > 1)
	  pairwise = true;
	if (freq == n)
	  setwise = true;
  }
  if (pairwise && setwise)
	std::cout << "not coprime" << std::endl;
  else if (pairwise)
	std::cout << "setwise coprime" << std::endl;
  else
	std::cout << "pairwise coprime" << std::endl;
}

