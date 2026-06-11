#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;


int main() {
	int n, k;
	cin >> n >> k;
	int maxK = (n - 1) * (n - 2) / 2;
	if (maxK < k) {
	
		cout << -1 << endl;
		return 0;
	}


	int m = n - 1 + (maxK - k);

	cout << m << endl;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {

			cout << i << " " << j << endl;
			cnt++;
			if (cnt >= m) {
				return 0;
			}
		}
	}

	

}


