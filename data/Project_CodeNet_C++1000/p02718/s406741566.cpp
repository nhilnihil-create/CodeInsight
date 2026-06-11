#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_popular_vote(void) {
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int select = 0;
	double thr = (sum*1.0) / (4 * m);

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if ((double) a[i] >= thr) select++;
	}

	if (select >= m) cout << "Yes" << endl;
	else             cout << "No" << endl;
}

int main()
{
    b_popular_vote();

    return 0;
}