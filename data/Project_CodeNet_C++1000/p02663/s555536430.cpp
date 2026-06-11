#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, h2, m1, m2, K;
    cin >> h1 >> m1 >> h2 >> m2 >> K;
    if (h1 == h2) cout << m2 - m1 - K << endl;
    else cout << 60 * (h2 - h1 - 1) + 60 - m1 + m2 - K << endl;
    return 0;
}