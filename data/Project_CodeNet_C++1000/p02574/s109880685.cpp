#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

int gcd(int a, int b) {
	if (a > b) {
		swap(a, b);
	}

	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> p{ 2 };
	for (int i = 3; i <= 1000; i++) {
		bool isPrime = true;
		for (int pi : p) {
			if (i % pi == 0) {
				isPrime = false;
			}
		}

		if (isPrime) {
			p.emplace_back(i);
		}
	}

	
	bool isPairwise = true;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int num = a[i];
		for (int pi: p) {

			if (num < pi) {
				break;
			}
			if (num % pi != 0) {
				continue;
			}

			if (s.find(pi) != s.end()) {
				isPairwise = false;
			}

			s.insert(pi);

			while (num % pi == 0) {
				num /= pi;

			}

			
		}

		if (num == 1) {
			continue;
		}

		if (s.find(num) != s.end()) {
			isPairwise = false;
		}

		s.insert(num);
	}

	if (isPairwise) {
		cout << "pairwise coprime" << endl;
		return 0;
	}

	int g = a[0];
	for (int i = 1; i < n; i++) {
		g = gcd(g, a[i]);

	}

	if (g == 1) {
		cout << "setwise coprime" << endl; 
	}
	else {
		cout << "not coprime" << endl;
	}

}