#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    vector <int> a(2);
    cin >> a[0] >> a[1];
    sort(a.begin(), a.end());
    for (int i=0;i<3;i++) {
        if (a[i]!=i+1) {
            cout << i+1;
            return 0;
        }
    }
    //cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    return 0;
}

