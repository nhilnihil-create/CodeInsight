#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

int main() {
	vector<int> prime;
	bool judge;
	prime.push_back(2);
	for (int i = 3; i < 1000; i++) {
		judge = true;
		for (int j = 0; j < (int)prime.size(); j++) {
			if (prime[j] > sqrt(i)) {
				break;
			}
			if (i % prime[j] == 0) {
				judge = false;
				break;
			}
		}
		if (judge) {
			prime.push_back(i);
		}
	}
	int N;
	cin >> N;
	int A;
	vector<int> pair(1000001);
	unordered_set<int> set;
	int n;
	bool judge_pair = true;
	for (int x : prime) set.insert(x);
	for (int i = 0; i < N; i++) {
		cin >> A;
		n = A;
		unordered_set<int> next_set;
		for (int j = 0; j < (int)prime.size(); j++) {
			if (prime[j] > sqrt(n)) break;
			if (n % prime[j] == 0) {
				if (judge_pair) {
					if (pair[prime[j]] == 0) pair[prime[j]] = 1;
					else judge_pair = false;
				}
				if (set.count(prime[j])) {
					next_set.insert(prime[j]);
				}
				if (set.count(A / prime[j])) {
					next_set.insert(A / prime[j]);
				}
				while (n % prime[j] == 0) {
					n /= prime[j];
				}
			}
		}
		if (n != 1) {
			if (judge_pair) {
				if (pair[n] == 0) pair[n] = 1;
				else judge_pair = false;
			}
			if (set.count(n)) {
				next_set.insert(n);
			}
		}
		set = next_set;
	}
	if (judge_pair) cout << "pairwise coprime" << endl;
	else if (set.empty()) cout << "setwise coprime" << endl;
	else cout << "not coprime" << endl;
}