#include<iostream>

using namespace std;


int main() {

	int n;
	int l[105];


	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((l[i] == l[j]) ||( l[j] == l[k]) || (l[i] == l[k]))continue;
				if ((l[i] >= (l[j] + l[k]) )|| (l[j] >= (l[i] + l[k]) )|| (l[k] >= (l[i] + l[j])))continue;
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}