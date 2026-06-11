#include <bits/stdc++.h>
using namespace std;

int main() {
	int h1, h2, m1, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
    if (h2 < h1)
      h2 += 24;
	int ans = (h2 - h1) * 60 + (m2 - m1) - k;
	cout << ans << endl;
}