#include<bits/stdc++.h>
using namespace std;
int main () {
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> a(n+1);
	for (int i=0; i<n; i++) {
		if (s[i] == '<') a[i+1] = max(a[i+1], a[i] + 1);	
	}
	for (int i=n-1; i>=0; i--) {
		if (s[i] == '>') a[i] = max(a[i], a[i+1] + 1);
	}
	long long res = accumulate(a.begin(), a.end(), 0LL);
	cout << res;
	return 0;
}