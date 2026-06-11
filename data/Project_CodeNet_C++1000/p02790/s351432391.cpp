#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int a, b;
    cin >> a >> b;

    string x = "";
    rep(i, b) {
        x += '0' + a;
    }

    string y = "";
    rep(i, a) {
        y += '0' + b;
    }

    if(x < y) {
        cout << x << endl;
    } else {
        cout << y << endl;
    }

    return 0;
}
