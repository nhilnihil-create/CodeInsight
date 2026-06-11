
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<random>

//#include<boost/circular_buffer.hpp>
using namespace std;

//cout << fixed << setprecision(10);
typedef long long ll;
#define PI 3.141592653589793
#define Yes(a) a ? "Yes" : "No";
#define YES(a) a ? "YES" : "NO";
#define rep(i,n) for(int i=0;i<n;i++)

long long int gcd(long long int a, long long int b) {
	if (a < b) {
		long long int tmp = a;
		a = b;
		b = tmp;
	}
	long long int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

long long int lcm(long long int a, long long int b) {
	long long int L;
	L = a / gcd(a, b);
	L *= b;
	return L;
}

vector<long long  int> Prime;
void Eratosthenes(long long int n) {
	vector<bool> is_prime(n, true);
	is_prime.at(0) = false;
	is_prime.at(1) = false;
	for (long long int i = 2; i * i <= n; i++) {
		if (is_prime.at(i)) {
			for (int j = i * i; j < n; j += i) {
				is_prime.at(j) = false;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (is_prime.at(i))
			Prime.emplace_back(i);
	}
}

/*
map<int, int> prime;
void Prime_number(long long int n) {
	for (int i = 2; i <= n; i++) {
		int count = 0;
		while (n % i == 0) {
			count++;
			n /= i;
		}
		if (count != 0) {
			prime.insert(make_pair(i, count));
		}
	}
}
*/
//std::cout.fill('0');

int keta(long long int N) {
	int k = 0;
	while (N > 0) {
		N /= 10;
		k++;
	}
	return k;
}

int Combination(int n, int m) {
	long long int s = 1, t = 1;
	int tmp = n;
	while (n - m != tmp) {
		s *= tmp;
		tmp--;
	}
	tmp = m;
	while (tmp != 1) {
		t *= tmp;
		tmp--;
	}
	return s / t;
}


int main() {
	int m, d, cnt = 0;
	cin >> m >> d;

	for (int i = 4; i <= m; i++) {
		for (int d1 = 2; d1 < 10; d1++) {
			for (int d2 = 2; d2 < 10; d2++) {
				if (d1 + 10 * d2 <= d && i == d1 * d2) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

