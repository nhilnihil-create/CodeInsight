#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin >> n;
    int M = 0;

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val < M) {
            cout << "No";
            return 0;
        }
        M = max(M, val - 1);
    }
    cout << "Yes" << "\n";

    return 0;
}