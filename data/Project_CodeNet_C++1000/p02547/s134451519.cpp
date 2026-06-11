#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> last_two(2, vector<int>(2));
    int cur = 0;
    bool ans = false;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i >= 2) {
            int count = 0;
            if (a == b && last_two[0][0] == last_two[0][1] && last_two[1][0] == last_two[1][1])
                ans = true;
        }
        last_two[cur][0] = a;
        last_two[cur][1] = b;
        cur = (cur + 1) % 2;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

	return 0;
}