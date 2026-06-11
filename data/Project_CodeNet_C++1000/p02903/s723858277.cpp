#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            cout << int((i < b && k < a) || (i >= b && k >= a));
        }
        cout << "\n";
    }
    return 0;
}
