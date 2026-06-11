#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int A, B;
	cin >> A >> B;

	int ans = 0;
	int total = 1;

	while (true) {
		if (total >= B) {
			break;
		}
		total += (A-1);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
