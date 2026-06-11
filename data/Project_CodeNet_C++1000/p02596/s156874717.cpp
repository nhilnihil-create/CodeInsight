#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    bool flag = true;
    vector<int> a(1000001);
    a[1] = 7 % k;
    for (int i = 2; i <= k; i++) {
        a[i] = (10 * a[i - 1] + 7)% k;
    }
    for (int i = 1; i <= k; i++) {
        if (a[i] == 0) {
            cout << i << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "-1" << endl;
    }
    return 0;
}