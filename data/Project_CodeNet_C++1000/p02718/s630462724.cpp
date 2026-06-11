#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;


int main() {
    double n, m;
    cin >> n >> m;
    double count = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        count += a.at(i);
    }
    sort(a.rbegin(), a.rend());
    bool x = false;
    for (int i = 0; i < m; i++) {
        if (a.at(i) < count / (4 * m)) {
            x = true;
        }
    }
    if (x) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }


}