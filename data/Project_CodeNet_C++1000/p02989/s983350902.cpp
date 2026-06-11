#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> d(N);
	int D = 0;
	for (int i = 0; i < N; i++) cin >> d[i];
	sort(d.begin(), d.end());
	int ans;
	int diff = d[N / 2] - d[N / 2 - 1];
	if (diff == 0) ans = 0;
	else ans = diff;
	cout << ans << endl;
	return 0;
}