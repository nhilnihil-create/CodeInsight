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

ll a[2], c[2];

int main(void) {
	cin >> a[0] >> a[1] >> c[0] >> c[1];
	ll ret = a[0] * c[0];
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++) {
			if (ret < a[i] * c[j])
				ret = a[i] * c[j];
		}
	cout << ret << endl;
	return 0;
}