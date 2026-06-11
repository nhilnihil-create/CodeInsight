#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int main() {
    int n;
    cin >> n;
    long long cur = 0;
    for (int i(1); i <= mx; ++i) {
        cur = cur * 10 + 7;
        cur %= n;
        if (cur == 0) {
            cout << i << endl;
            return 0;
        }

    }
    cout << -1 << endl;
}