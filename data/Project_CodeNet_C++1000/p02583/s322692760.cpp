#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* l = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> l[i];
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i+1;j < n;j++) {
			for (int k = j + 1;k < n;k++) {
				if (l[i] != l[j] && l[i] != l[k] && l[j] != l[k] && l[i] < l[j] + l[k] && l[j] < l[i] + l[k] && l[k] < l[i] + l[j]) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}