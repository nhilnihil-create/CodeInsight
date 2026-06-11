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
    vector<int> a(n);
    vector<ll> d(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        d[a[i]]++;
    }
    ll sum = 0;
    rep(i, n+1) {
        if (d[i] >= 2) {
            sum += (d[i] * (d[i] - 1)) / 2;
        }
    }
    rep(i, n) {
        cout << sum - (d[a[i]] - 1) << endl;
    }
    return 0;
}