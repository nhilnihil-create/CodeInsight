#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9 + 7);

int x;

int main(void) {
	cin >> x;
	int ret = 0;
	if (x == 0)
		ret = 1;
	cout << ret << endl;
	return 0;
}