#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Minimum_Prime_Factors {
	vector<int> minimum_prime_factors;

public:
	Minimum_Prime_Factors(int& n) : minimum_prime_factors(n + 1) {
		for (int i = 0; i <= n; i++) {
			minimum_prime_factors[i] = i;
		}
		for (int i = 2; i * i <= n; i++) {
			if (minimum_prime_factors[i] == i) {
				for (int j = i * i; j <= n; j += i) {
					if (minimum_prime_factors[j] == j) {
						minimum_prime_factors[j] = i;
					}
				}
			}
		}
	}

	int get_minimum_prime_factor(int& a) {
		return minimum_prime_factors[a];
	}
};

unordered_set<int> prime_factorization_unique(int a, Minimum_Prime_Factors& minimum_prime_factors) {
	unordered_set<int> prime_factors_unique;
	while (1 < a) {
		prime_factors_unique.insert(minimum_prime_factors.get_minimum_prime_factor(a));
		a /= minimum_prime_factors.get_minimum_prime_factor(a);
	}
	return prime_factors_unique;
}

vector<unordered_set<int>> A_prime_factorization_unique(vector<int>& A) {
	vector<unordered_set<int>> A_prime_factors_unique;
	Minimum_Prime_Factors minimum_prime_factors(*max_element(A.begin(), A.end()));
	for (int& i : A) {
		A_prime_factors_unique.push_back(prime_factorization_unique(i, minimum_prime_factors));
	}
	return A_prime_factors_unique;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A) {
		cin >> i;
	}
	vector<unordered_set<int>> A_prime_factors_unique;
	A_prime_factors_unique = A_prime_factorization_unique(A);
	bool pairwise_coprime = true;
	unordered_set<int> prime_factors_unordered_set;
	for (unordered_set<int>& i : A_prime_factors_unique) {
		for (const int& j : i) {
			if (prime_factors_unordered_set.find(j) != prime_factors_unordered_set.end()) {
				pairwise_coprime = false;
				break;
			}
			prime_factors_unordered_set.insert(j);
		}
		if (!pairwise_coprime) {
			break;
		}
	}
	if (pairwise_coprime) {
		cout << "pairwise coprime" << endl;
		return 0;
	}
	int A_gcd = A.front();
	for (int i = 1; i < N; i++) {
		A_gcd = gcd(A[i], A_gcd);
	}
	if (A_gcd == 1) {
		cout << "setwise coprime" << endl;
		return 0;
	}
	cout << "not coprime" << endl;
}