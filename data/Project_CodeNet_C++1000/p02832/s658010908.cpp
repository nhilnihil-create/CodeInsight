#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    int sh = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) != sh) {
            cnt++;
        }
        else {
            sh++;
        }
    }
    if (cnt == n) {
        cout << -1 << endl;
    }
    else {
        cout << cnt << endl;
    }
    return 0;
}