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
	int K, N;
	int ans = INF;
	int sum = 0;
	cin >> K >> N;
	vector<int> a(N);

	vector<int> b(N) ;
	for (int i = 0; i < N; i++)cin >> a.at(i);
	for (int i = 0; i < N-1; i++)b.at(i) = a.at(i + 1) - a.at(i);
	b.at(N - 1) = K - a.at(N - 1) + a.at(0);
	for (int i = 0; i < N; i++)sum += b.at(i);
	for (int i = 0; i < N; i++) {
		if (ans> sum - b.at(i))ans = sum - b.at(i);
	}
	cout << ans << endl;
	return 0;
}
