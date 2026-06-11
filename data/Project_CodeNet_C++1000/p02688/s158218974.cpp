#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> snuke(n, 0);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            snuke[a - 1]++;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (snuke[i] == 0) count++;
    }
    cout << count << endl;

	return 0;
}