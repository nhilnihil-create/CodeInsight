#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, bk, l = 0; cin >> N >> bk;
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        if (abs(x - bk) > 1) {
            if (bk > x) {
                cout << "No" << endl;
                return 0;
            }
        } else if (x == bk) continue;
        bk = x - 1;
        l = max(l, x-1);
        if (l > bk) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}