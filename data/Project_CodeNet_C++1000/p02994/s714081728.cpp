#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, l;
int main() {
    cin >> n >> l;
    int left = l;
    int right = l + n - 1;
    int sum = (left + right) * n / 2;
    if (left >= 0) {
        cout << sum - l << endl;
    } else if (right <= 0) {
        cout << sum - right << endl;
    } else {
        cout << sum << endl;
    }
    return 0;
}
