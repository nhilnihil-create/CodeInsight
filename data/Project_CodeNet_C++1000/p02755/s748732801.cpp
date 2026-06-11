#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	bool flag = false;
	for (int i = 1; i <= 1000 && !flag; i++) {
		if ((i * 8) / 100 == a && i / 10 == b) {
			cout << i << endl;
			flag = true;
		}
	}
	if (!flag) cout << -1 << endl;

	return 0;
}