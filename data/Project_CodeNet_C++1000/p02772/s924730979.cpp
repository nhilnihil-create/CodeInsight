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
    for (int i = 0; i < n; i++) {
        if (a.at(i) % 2 != 0) {
            continue;
        }
        if (a.at(i) % 3 == 0 || a.at(i) % 5 == 0) {
            continue;
        }
        ans = false;
    }
    if (ans) {
        cout << "APPROVED" << endl;
    }
    else {
        cout << "DENIED" << endl;

    }
}
