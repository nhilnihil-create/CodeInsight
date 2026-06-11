#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r, d;
    cin >> l >> r >> d;
    int count = 0;
    for (; l <= r; ++l) {
        if (l % d == 0)
            ++count;
    }
    cout << count << "\n";
    return 0;
}
