#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b;
    cin >> a >> b;
    ll c = abs(a+b);
    if (c%2 == 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << c/2 << endl;  
    }

    return 0;
}