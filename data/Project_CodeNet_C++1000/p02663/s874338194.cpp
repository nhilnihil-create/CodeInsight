#include <bits/stdc++.h>

using namespace std;

int main() {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    if (m1 < m2) {
        h2--;
        m2 += 60;
    }
    int up = (h2 - h1) * 60 + (m2 - m1);
    cout << up - k << endl;
    return 0;
}
