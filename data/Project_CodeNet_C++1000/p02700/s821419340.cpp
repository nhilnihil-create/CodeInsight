#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int taka = ceil(a/float(d)), ao = ceil(c/float(b));
    if (taka == ao || taka > ao)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}