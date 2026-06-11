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

long long A, B, C, K;

int main() {
	cin >> A >> B >> C >> K;
	if (K <= A) cout << K << endl;
	else if (K <= A + B) cout << A << endl;
	else cout << A - (K - A - B) << endl;
	return 0;
}