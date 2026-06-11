#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N, R;
    cin >> N >> R;

    if (N >= 10) {
        cout << R << endl;
    } else
    {
        R = R + (100 * (10 - N));
        cout << R << endl;
    }

    return 0;
}