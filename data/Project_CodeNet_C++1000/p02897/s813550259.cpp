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
	double cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) { if ((i+1) % 2 == 1) { cnt += 1; } }
	//cout << cnt << endl;
	cout << cnt / N << endl;
		return 0;
}
