#include <bits/stdc++.h>
using namespace std;

int main () {
    int x, n;
    cin >> x >> n;
    if (n == 0) {
        cout << x << endl;
    }
    else {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());
        int a;
        for (int i = 0; i <= 100; i++) {
            for (int j : {-1, 1}) {
                a = x + i * j;
                if (count(p.begin(), p.end(), a) == 0) {
                    cout << a << endl;
                    return 0;
                }
            }
        }
    }
}