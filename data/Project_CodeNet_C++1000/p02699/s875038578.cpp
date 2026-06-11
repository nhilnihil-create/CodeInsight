#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double PI = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll s, w;
    cin >> s >> w;
    if (w >= s) {
        cout << "unsafe\n";
    } else {
        cout << "safe\n";
    }

    return 0;
}
