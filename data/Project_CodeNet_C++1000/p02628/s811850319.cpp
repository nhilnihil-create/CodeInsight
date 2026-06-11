#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    rep(i, n) cin >> p.at(i);

    sort(p.begin(), p.end());
    int sum = 0;
    for (size_t i = 0; i < k; i++) {
        sum += p.at(i);
    }
    cout << sum << endl;
}
