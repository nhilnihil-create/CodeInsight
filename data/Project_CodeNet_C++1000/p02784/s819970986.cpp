#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, n;
    cin >> h >> n;

    int sum = 0, tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
    }

    if (h <= sum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
