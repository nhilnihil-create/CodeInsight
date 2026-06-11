#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, cnt = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> A;
        cnt += A;
    }

    if (cnt >= 22) {
        cout << "bust" << endl;
        return 0;
    } else {
        cout << "win" << endl;
        return 0;
    }
}