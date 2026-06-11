#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, k, i, j;
	vector<int> a, b;

	scanf("%d%d", &n, &k);

	for (i = 1; i < n; i++) {
		a.push_back(0);
		b.push_back(i);
	}

	for (i = 1; i < n - 1; i++) for (j = i + 1; j < n; j++) {
		if (k > 0) {
			k--;
		}
		else {
			a.push_back(i);
			b.push_back(j);
		}
	}

	if (k > 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", a.size());
		for (i = 0; i < a.size(); i++) {
			printf("%d %d\n", a[i] + 1, b[i] + 1);
		}
	}

	return 0;
}