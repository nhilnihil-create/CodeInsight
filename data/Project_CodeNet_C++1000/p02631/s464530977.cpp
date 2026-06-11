#include <bits/stdc++.h>

using namespace std;

using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define delete

const static int MOD = 1000000007;
const static int INF = 1<<30;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    int xor_all = 0;
    rep(i, n) xor_all = A[i]^xor_all;

    rep(i, n) cout << (xor_all^A[i]) << ' ';
    cout << endl;

    return 0;
}