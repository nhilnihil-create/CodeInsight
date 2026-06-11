#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    long long k; cin >> k;

    vector<long long> a(n);
    vector<long long> b(n);

    for (int i= 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i= 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long lo = -1, hi = a.back() * b.back();

    while (lo + 1 < hi) {
        long long m = (lo + hi) / 2;
        // auto m = 1;
        auto r = k;

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            auto A = a[n - i - 1];
            auto B = b[i];

            if (A * B - m <= 0)
                continue;

            long long t = (A * B - m + B - 1) / B;
            if (t > r) {
                ok = false;
                break;
            }

            r -= t;
        }

        if (ok)
            hi = m;
        else
            lo = m;
    }

    cout << hi << endl;

    return 0;
}