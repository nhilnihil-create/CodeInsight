#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    if (n == 0) {
        cout << x << endl;
    } else {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int closest, minAbs;
        minAbs = 1000;
        for (int i = 0; i <= 101; i++) {
            if (find(p.begin(), p.end(), i) == p.end()) {
                if (abs(x - i) < minAbs) {
                    closest = i;
                    minAbs = abs(x - i);
                }
            }
        }

        cout << closest << endl;
    }

    return 0;
}