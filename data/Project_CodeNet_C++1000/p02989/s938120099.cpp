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
	cin >> N;
	vector<int> d(N);
	for (int i = 0; i < N; i++) {
		cin >> d.at(i);
	}
	sort(d.begin(), d.end());
	cout << d.at(N/ 2) - d.at(N / 2-1) << endl;
		return 0;
}
