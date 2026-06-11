#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	int minv = min(h, w);
	int maxv = max(h, w);
	int masu = 0;
	for (int i = 1; i <= minv; i++) {
		masu += maxv;
		if (n <= masu) {
			cout << i << endl;
			return 0;
		}
	}
}
