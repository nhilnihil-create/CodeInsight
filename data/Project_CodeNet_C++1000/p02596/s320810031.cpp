#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int k;
    cin >> k;

    vector<int> a(1000001);
    a[1] = 7;
    for (int i = 2; i <= k; i++) a[i] = (a[i-1] * 10 + 7) % k;

    for (int i = 1; i <= k; i++) {
        if (a[i] % k == 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}
