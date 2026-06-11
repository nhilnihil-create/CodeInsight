#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	double value = (v[0] + v[1]) * 1.0 / 2;
	for (int i = 2; i < N; i++) {
		value = (value + v[i]) / 2;
	}
	cout << fixed << setprecision(5) << value << endl;
	return 0;
}