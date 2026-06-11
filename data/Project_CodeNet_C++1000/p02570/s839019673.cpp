#include <bits/stdc++.h>

using namespace std;

int main() {
    int d,t,s;
    cin >> d >> t >> s;
    if ((d / s + (d % s == 0 ? 0 : 1)) > t) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}
