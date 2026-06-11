#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a.at(x - 1);
    }
    sort(a.begin(), a.end());
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i) s.at(i + 1) = s.at(i) + a.at(i);
    for (int k = 1; k <= n; ++k) {
        int l = 0, r = n / k + 1;
        while (l + 1 < r) {
            int c = (l + r) / 2;
            bool ok = [&](int c) {
                int i = lower_bound(a.begin(), a.end(), c) - a.begin();
                int sum = c * (n - i) + s.at(i);
                return (sum >= c * k);
            }(c);
            if (ok) l = c; else r = c;
        }
        cout << l << endl;
    }
    return 0;
}