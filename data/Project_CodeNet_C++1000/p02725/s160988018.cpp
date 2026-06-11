#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        if (i == 0) continue;
        if (max < a.at(i) - a.at(i-1)) max = a.at(i) - a.at(i-1);
    }
    if (max < a.at(0) + k - a.at(n-1)) max = a.at(0) + k - a.at(n-1);

    cout << k - max << endl;

    return 0;
}
