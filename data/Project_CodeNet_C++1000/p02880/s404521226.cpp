#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;

    bool y = 0;
    for (int i = 1; i < 10; i++)
        if (((n / i) * i == n) && ((n / i) < 10))
            y = 1;
    cout << ((y) ? "Yes" : "No");
}
