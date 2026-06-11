#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    ll x;
    cin >> x;
    ll a, b;
    for (a = -120; a <= 120; a++)
        for (b = -120; b <= 120; b++)
            if (pow(a, 5)-pow(b, 5) == x) {
                cout << a << " " << b << endl;
                return 0;
            }
    return 0;
}