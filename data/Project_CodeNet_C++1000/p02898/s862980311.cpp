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
	int N,K;
	int ans = 0;
	cin >> N>>K;
	vector<int> a(N);
	//vector<int> b(N);
	for (int i = 0; i < N; i++)cin >> a.at(i);
	for (int i = 0; i < N; i++) {
		if (a.at(i) >= K)ans++;
	}
	cout << ans << endl;
	
		return 0;
}
