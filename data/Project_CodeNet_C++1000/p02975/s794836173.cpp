#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    unsigned int a = 0;
    for (int i = 0; i < N; ++i) {
        unsigned int b;
        cin >> b;
        a ^= b;
    }

    if (a == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
