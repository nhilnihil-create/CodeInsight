#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, A, B;

int main() {
	cin >> A >> B >> N;
	long long T = A * min(N, B - 1LL) / B;
	cout << T << endl;
	return 0;
}