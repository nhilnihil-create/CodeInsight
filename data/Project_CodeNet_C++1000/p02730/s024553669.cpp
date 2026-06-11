#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    string o, s;
    cin >> o;
    s = o;
    reverse(o.begin(), o.end());
    if (s != o) {
        cout << "No" << endl;
        return 0;
    }
    if (o.substr(0, o.size() / 2) !=
        o.substr((o.size() + 3) / 2 - 1, o.size() / 2)) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}