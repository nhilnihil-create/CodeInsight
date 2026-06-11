#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;

    if (c-a-b > 0 && 2*a*b + 2*b*c + 2*c*a < a*a + b*b + c*c) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
