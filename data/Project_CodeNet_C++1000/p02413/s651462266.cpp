#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c, sum = 0;
    cin >> r >> c;

    int x[c] = {};

    while (r--) {
        int sum = 0;

        for (int i = 0; i < c; ++i) {
            int t;
            cin >> t;
            x[i] += t;
            sum += t;
            cout << t << " ";
        }

        cout << sum << endl;
    }

    for (int i = 0; i < c; ++i) {
        sum += x[i];
        cout << x[i] << " ";
    }

    cout << sum << endl;

    return 0;
}