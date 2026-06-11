#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> aa = a;
	sort (aa.begin(), aa.end());
	int m1 = aa[n-1], m2 = aa[n-2];
	for (int i = 0; i < n; i++) {
		if (a[i] != m1)
			cout << m1 << endl;
		else
			cout << m2 << endl;
	}
}