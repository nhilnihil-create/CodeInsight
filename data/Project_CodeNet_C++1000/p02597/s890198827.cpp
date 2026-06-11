#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char a[n];
	for (int i = 0; i < n; i++) {
		a[i] = s[i];
	}

	int i = 0;
	int j  = n - 1;
	int ans  =  0;
	while (i < j) {
		while (a[i] == 'R' && i < j) {
			i++;
		}
		while (j > i && a[j] == 'W') {
			j--;
		}
		if (i < j) {
			ans++;
			char temp  = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	cout << ans << endl;
}