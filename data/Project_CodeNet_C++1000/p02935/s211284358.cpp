#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	double ans = 0;
	double sm = a[0];
	int i = 1;

	while(i < n) {
      sm = (a[i] + sm) / 2;
      i++;
	}
	printf("%.2f\n", sm);
}