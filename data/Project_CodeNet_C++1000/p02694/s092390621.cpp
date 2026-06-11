#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll solve() {
    ll n; cin >> n;
    ll cnt = 0, cur = 100;
    while (cur < n) {
        cur += cur / 100;
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
