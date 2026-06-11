#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, idx = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++) {
        if (a.at(i) == idx + 1) {
            idx++;
        }
    }
    cout << (idx != 0 ? n - idx : -1) << endl;
}