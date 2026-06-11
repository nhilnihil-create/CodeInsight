#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int h[100000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (h[i - 1] - h[i] >= 2) {
            cout << "No" << endl;
            return 0;
        } else if (h[i - 1] - h[i] == 1) h[i]++;
    }
    cout << "Yes" << endl;
}
