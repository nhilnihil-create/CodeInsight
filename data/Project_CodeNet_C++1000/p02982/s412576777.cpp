#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> y, vector<int> z, int n) {
    double x = 0;
    for (int i = 0; i < n; i++) {
        x += (y.at(i) - z.at(i)) * (y.at(i) - z.at(i));
    }
    x = sqrt(x);
    return floor(x) == ceil(x);
}

int main(void) {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < d; ii++) {
            cin >> x.at(i).at(ii);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int ii = 0; ii < i; ii++) {
            if (f(x.at(i), x.at(ii), d)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}