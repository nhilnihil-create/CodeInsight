#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int k;
	cin >> k;
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int z = 1; z <= k; z++) {
				sum += __gcd(__gcd(i, j), z);
			}
		}
	}
	cout << sum;
}
	