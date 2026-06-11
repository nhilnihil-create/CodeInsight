#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	int N;
	double X = 0;
	cin >> N;
	vector<double> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
		X += 1/v.at(i);
	}
	cout << 1 / X << endl;
	return 0;
}