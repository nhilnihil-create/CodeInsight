#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int solve() {
    int n, k; cin >> n >> k;
    vi v(n, 0);
    for (int i = 1; i <= k; ++i) {
        int d; cin >> d;
        int a;
        while (d--) {
            cin >> a;
            v[a - 1]++;
        }
    }

    int cnt = 0;
    for (auto num : v) {
        if (num == 0) 
            cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
