#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != i+1) count++;
    }

    if (count <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}