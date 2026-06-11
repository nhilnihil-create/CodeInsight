#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int A[3];

int main() {
	cin >> A[0] >> A[1] >> A[2];
	sort(A, A + 3);
	cout << A[0] + A[1] << endl;
	return 0;
}