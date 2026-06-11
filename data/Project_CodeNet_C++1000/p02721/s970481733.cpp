
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;

	vector<int> l(k);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			l[cnt] = i;
			cnt++;
			i += c;
		}

		if (cnt == k) {
			break;
		}

	}

	cnt = k - 1;
	vector<int> r(k);
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'o') {
			r[cnt] = i;
			cnt--;
			i -= c;
		}
		if (cnt < 0) {
			break;
		}

	}


	

	for (int i = 0; i < k; i++) {
		if (l[i] == r[i]) {
			cout << l[i] + 1 << endl;
		}
	}
	
}