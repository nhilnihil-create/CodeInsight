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

int n, x, l;
int main() {
    cin >> n >> x;
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        sum += l;
        if (sum > x) {
            cout << cnt << endl;
            exit(0);
        }
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
