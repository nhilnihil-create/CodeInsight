#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int XOR = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i], XOR ^= v[i];
    sort(v.begin(), v.end());

    if (n % 3 == 0) {
        cout << (v[n / 3 * 0] == v[n / 3 * 1 - 1] &&
                 v[n / 3 * 1] == v[n / 3 * 2 - 1] &&
                 v[n / 3 * 2] == v[n / 3 * 3 - 1] &&
                 XOR == 0 ? "Yes" : "No") << endl;
    } else {
        cout << (v[0] == v[n - 1] ? "Yes" : "No") << endl;
    }
    return 0;
}