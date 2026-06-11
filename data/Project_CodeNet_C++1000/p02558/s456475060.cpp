#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v) {
    os << "(" << v.first << ", " << v.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "}";
    return os;
}

int main()
{
    int n, q;
    cin >> n >> q;

    atcoder::dsu d(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << d.same(u, v) << endl;
        }
    }

    return 0;
}