#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    int n; cin >> n;
    int rtn = 0;
    for (int i = 1; i <= n; ++i) {
        int dig = log10(i) + 1;
//        cout << dig << endl;
        if (dig % 2 != 0) ++rtn;
    }
    cout << rtn << endl;
}
