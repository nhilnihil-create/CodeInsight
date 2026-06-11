#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[200000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int max = 0, maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            maxIdx = i;
        }
    }
    int sec = 0, secIdx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > sec && i != maxIdx) {
            sec = a[i];
            secIdx = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == maxIdx) cout << sec << endl;
        else cout << max << endl;
    }
}
