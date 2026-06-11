

#define _USE_MATH_DEFINES

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

const ll MOD = 1e9 + 7;


int main(int argc, char* argv[]) {
	
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int ai : a) {
		sum += ai;
	}

	int ans = n - sum;
	if (ans < 0) {
		ans = -1;
	}

	cout << ans << endl;
	


}