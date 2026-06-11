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
#include <complex>

using namespace std;

#define endl '\n'

typedef complex<long long> point;

int semi(point &a) {
    if (a.imag() == 0 && a.real() >= 0) return 0;
    if (a.imag() > 0) return 0;
    return 1;
}

long long cross(point &a, point &b) {
    return imag(conj(a) * b);
}

long long dot(point &a, point &b) {
    return real(conj(a) * b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<point> p(n);

    for (int i = 0; i < n; ++i) {
        long long x, y; cin >> x >> y;
        p[i] = point(x, y);
    }

    long long ans = 0;

    sort(p.begin(), p.end(), [&](point &a, point &b){
        int sa = semi(a), sb = semi(b);
        if (sa != sb) return sa < sb;
        if (cross(a, b) == 0)
            return dot(a, a) < dot(b, b);
        return cross(a, b) > 0;
    });

    for (int i = 0; i < n; ++i){
        auto x = p[i];
        p.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        point u(0);
        for (int j = 0; j < n; ++j) {
            u += p[i + j];
            ans = max(ans, real(conj(u) * u));
        }
    }

    cout.precision(15);
    cout << fixed << sqrtl((long double)ans) << endl;

    return 0;
}