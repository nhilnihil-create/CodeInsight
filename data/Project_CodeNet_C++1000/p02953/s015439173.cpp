#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
    	if (a[i] - b[i] >= 2) {
    		cout << "No" << "\n";
    		return 0;
    	}
    }
    cout << "Yes" << "\n";
    return 0;
}