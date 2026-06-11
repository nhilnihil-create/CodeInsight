#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    bool ans = true;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        if (a.at(i) == a.at(i + 1)) {
            ans = false;
        }
    }
    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}