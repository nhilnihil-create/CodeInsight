#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int A, B, M;
	cin >> A >> B >> M;
	
	vector<ll> a(A), b(B);
	for(int i = 0; i < A; ++i) {
		cin >> a[i];
	}
	
	for(int i = 0; i < B; ++i) {
		cin >> b[i];
	}
	
	ll amin = *min_element(a.begin(), a.end());
	ll bmin = *min_element(b.begin(), b.end());
	
	ll ans = amin + bmin;
	
	vector<int> x(M), y(M);
	vector<ll> c(M);
	
	for(int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i] >> c[i];
		
		ans = min(ans, a[x[i] - 1] + b[y[i] - 1] - c[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
