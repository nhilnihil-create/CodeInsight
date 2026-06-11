#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c;
    cin >> k;
    for (int i = 0; i <= k; i++)
    {
        if (a < b && b < c) {
            cout << "Yes" << endl;
            return 0;
        }
        if (a >= b) {
            b *= 2;
        }
        else if (b >= c) {
            c *= 2;
        }
        
    }
    cout << "No" << endl;
    return 0;
}