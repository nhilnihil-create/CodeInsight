#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string res = "No";
    if (a == b && a != c) res = "Yes";
    if (b == c && a != b) res = "Yes";
    if (a == c && b != c) res = "Yes";

    cout << res << endl;

    return 0;
}
