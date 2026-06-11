#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int m, d;
    cin >> m >> d;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            if (j % 10 < 2 || j / 10 < 2) continue;
            if ((j % 10) * (j / 10) == i) sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
