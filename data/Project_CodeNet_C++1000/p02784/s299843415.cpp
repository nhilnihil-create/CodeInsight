#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_common_raccoon_vs_monster(void) {
	long long h, n;
	cin >> h >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		h -= a[i];
	}

	if (h <= 0) cout << "Yes" << endl;
	else        cout << "No" << endl;

}

int main()
{
    b_common_raccoon_vs_monster();

    return 0;
}