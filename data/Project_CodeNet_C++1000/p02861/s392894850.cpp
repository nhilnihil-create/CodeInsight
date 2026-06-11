#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

int N;
vector<int> x(10);
vector<int> y(10);


double dist(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return pow(dx * dx + dy * dy, 0.5);
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	long double ans = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) vec[i] = i ;
	do {
		for (int i = 0; i < N - 1; i++) ans += dist(vec[i], vec[i + 1]);
	} while (next_permutation(vec.begin(), vec.end()));
	int factorial = 1;
	for (int i = 2; i <= N; i++) factorial *= i;
	cout << fixed << setprecision(10) << ans / factorial << endl;
}
