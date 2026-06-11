#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

ll pow5(ll a) { return a * a * a * a * a; }

int main() {
    ll x;
    cin >> x;
    ll i = -200, j = -200;
    while (true) {
        j = -200;
        while (true) {
            if (pow5(i) - pow5(j) == x) break;
            if (j == 200) break;
            j++;
        }
        if (pow5(i) - pow5(j) == x) break;
        i++;
    }
    cout << i << " " << j << endl;
    return 0;
}