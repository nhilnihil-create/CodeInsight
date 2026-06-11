#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    int a_x = a, b_x = b;
    for (int i = 1; i < b; i++) {
        a_x *= 10;
        a_x += a;
    }
    for (int i = 1; i < a; i++) {
        b_x *= 10;
        b_x += b;
    }

    if (a < b) {
        cout << a_x << endl;
    } else {
        cout << b_x << endl;
    }

    return 0;
}
