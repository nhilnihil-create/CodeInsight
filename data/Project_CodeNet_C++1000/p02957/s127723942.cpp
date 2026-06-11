#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int64_t A, B, ans;
    cin >> A >> B;
    int64_t mx = max(A, B);
    bool is_ans = false;
    for (int64_t i=0; i < mx; i++) {
        if (abs(A - i) == abs(B - i)) {
            ans = i;
            is_ans = true;
            break;
        }
    }

    if (is_ans) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}