#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long double l;
    cin >> l;
    cout << setprecision(10) << fixed << (l/3) * (l/3) * (l/3) << "\n";
}
