#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int a, b;

    cin >> a >> b;

    for (ll i = a; i <= (ll)a*b; i+=a) {
        if (i % b == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}