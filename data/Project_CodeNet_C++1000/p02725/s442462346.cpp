#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int k, n;
    int ans = 0;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        d.at(i) = a.at(i) - a.at(i - 1);
    }
    d.at(0) = (k - a.at(n - 1)) + a.at(0);
    sort(d.begin(), d.end());
    for (int i = 0; i < n - 1; i++) {
        ans += d.at(i);
    }
    cout << ans << endl;
}