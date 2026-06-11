#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second ;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].first == arr[i].second) {
			count += 1;
		}
		else {
			if (count == 3) {
				break;
			}
			else {
				count = 0;
			}
		}
	}
	if (count >= 3) cout << "Yes\n";
	else cout << "No\n";
}