#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n, 0);
    vector<ll> y(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    ll max_u = - 10e17;
    ll min_u = 10e17;
    ll max_v = - 10e17;
    ll min_v = 10e17;
    for (int i = 0; i < n; i++) {
        max_u = max(x[i] + y[i], max_u);
        max_v = max(x[i] - y[i], max_v);
        min_u = min(x[i] + y[i], min_u);
        min_v = min(x[i] - y[i], min_v);
    }
    cout << max(max_u - min_u, max_v - min_v) << endl;
    return 0;
}