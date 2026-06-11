#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    int n;
    cin >> n;
    string a,b;
    cin >> a>> b;
    for (int i=0;i<n;i++) {
        cout << a[i] << b[i];
    }
    //cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    return 0;
}

