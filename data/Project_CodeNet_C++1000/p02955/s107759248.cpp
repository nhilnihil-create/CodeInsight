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


const int BIG_INT = 1000000000;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int maxG = sum / n;
	if (sum % n != 0) {
		maxG++;
	}

	set<int> cd;
	for (int i = 1; i <= maxG; i++) {
		if (i > sum) {
			break;
		}

		if (sum % i == 0) {
			cd.insert(i);
		}
	}

	for (int i = 1; i < n; i++) {
		if (sum % i == 0) {
			cd.insert(sum / i);
		}
	}

	int ans = 0;
	for (auto it = cd.begin(); it != cd.end(); it++) {
		
		vector<int> rem(n);
		for (int i = 0; i < n; i++) {
			rem[i] = a[i] % (*it);
		}

		sort(rem.begin(), rem.end());

		int cnt = 0;
		int rp = n - 1;
		int r = 0;
		for (int i = 0; i < n; i++) {
		
			if (i == rp) {

				break;
			}
			
			r += rem[i];
			cnt += rem[i];
			while (r > 0) {
				if (rem[rp] + r > (*it)) {
					r -= (*it) - rem[rp];
					rp--;
				}
				else {
					rem[rp] += r;
					r = 0;
				}
			}
			
		}

		

		if (cnt <= k) {
			ans = max(ans, *it);
		}
	}

	cout << ans << endl;
}

