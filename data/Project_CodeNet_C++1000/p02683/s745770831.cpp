

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


const int BIG_NUM = 1e8;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<int>> book(n, vector<int>(m + 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			cin >> book[i][j];
		}
	}


	int ans = BIG_NUM;
	for (int b = 0; b < (1 << n); b++) {
		vector<int> a(m);
		int cost = 0;
		for (int i = 0; i < n; i++) {
			if (((b >> i) & 1) == 1) {
				for (int j = 0; j < m; j++) {
					a[j] += book[i][j + 1];
				}

				cost += book[i][0];

				
			}
			
			
		}
		


		bool canAchieve = true;
		for (int i = 0; i < m; i++) {
			if (a[i] < x) {
				canAchieve = false;
			}
		}


		
		if (!canAchieve) {
			continue;
		}

		

		ans = min(ans, cost);
	}

	if (ans == BIG_NUM) {
		ans = -1;
	}

	cout << ans << endl;


}