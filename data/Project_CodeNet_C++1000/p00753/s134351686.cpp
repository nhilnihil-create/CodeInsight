#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

list<int> Prime(int num) {
	list<int>P;
	P.push_back(2);
	P.push_back(3);
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (j*j > i) {
				break;
			}
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if (j*j > i + 2) {
				break;
			}
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	return P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<int>P = Prime(123456 * 2);
	cin >> N;
	while (N) {
		M = 0;
		for (auto i : P) {
			if (i > N&&i <= N * 2) {
				M++;
			}
			if (i > N * 2) {
				break;
			}
		}
		cout << M << endl;
		cin >> N;
	}
	return 0;
}