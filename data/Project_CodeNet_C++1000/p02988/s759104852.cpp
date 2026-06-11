#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)cin >> p[i];

    int ret = 0;
    for (int i = 1; i < n - 1; i++) {
        bool found = false;
        if (p[i - 1] < p[i] && p[i] < p[i + 1])found = true;
        if (p[i - 1] > p[i] && p[i] > p[i + 1])found = true;
        if (found) ret++;
    }

    cout << ret << endl;
    return 0;
}