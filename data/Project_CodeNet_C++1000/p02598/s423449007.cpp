#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int INF = 1000000000;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> logs(n);
    rep(i, n) cin >> logs[i];

    int left = 0, right = INF, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        int cut = 0;
        rep(i, n) {
            if (cut > k) break;
            cut += (logs[i] + mid - 1) / mid - 1;
        }
        if (cut <= k) right = mid;
        else left = mid;
    }

    cout << right << endl;

    return 0;
}