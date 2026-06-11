#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N;
	cin >> N;
	vector<int> As(N);
	vector<ll> NumberList(N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> As[i];
		NumberList[As[i]]++;
	}

	ll total = 0;
	for (int k = 1; k <= N; k++) {
		total += NumberList[k] * (NumberList[k] - 1) / 2;
	}
	for (int k = 1; k <= N; k++) {
		int nk = NumberList[As[k-1]];
		if (nk == 0){
			print(total);
		}
		else {
			print(total - nk * (nk - 1) / 2 + (nk - 1) * (nk - 2) / 2);
		}
	}
}

