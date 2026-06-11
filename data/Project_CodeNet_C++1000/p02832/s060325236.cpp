#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == idx + 1) {
            idx++;
        }
    }
    cout << (idx != 0 ? n - idx : -1) << endl;
}