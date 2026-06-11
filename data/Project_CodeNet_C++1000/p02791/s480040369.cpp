#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int min_p = INT_MAX, cnt = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        min_p = min(min_p, p);
        if (p == min_p)
            cnt++;
    }

    cout << cnt << endl;
}