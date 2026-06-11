#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1e3 + 10;
int n, a[MAXX], b[MAXX];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for(int i = 0; i + 2 < n; i++)
		if(a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2])
			return cout << "Yes" << endl, 0;
	return cout << "No" << endl, 0;
}