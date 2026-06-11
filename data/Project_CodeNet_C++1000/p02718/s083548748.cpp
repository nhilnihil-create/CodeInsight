
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;


int main(int argc, char* argv[]) {

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] * 4 * m >= sum) {
			cnt++;
		}
	}

	if (cnt >= m) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}


}