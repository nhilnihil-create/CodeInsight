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

const int N = 10;
int n, d;
int a[N][N];
int cnt;

inline bool check(int x) {
    int y = sqrt(x);
    return y * y == x;
}

int main() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = 0;
            for (int k = 0; k < d; ++k) {
                int d = a[i][k] - a[j][k];
                dist += d * d;
            }
            if (check(dist))
                ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
