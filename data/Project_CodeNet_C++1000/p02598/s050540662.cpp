#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 2e5 + 5;
int n;
ll k, ans;
int a[N];

bool check(int x) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= x) {
            cnt += (a[i] + x - 1) / x - 1;
        }
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 1e9;
    while (l < r) {
        int m = (r - l) / 2 + l;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
