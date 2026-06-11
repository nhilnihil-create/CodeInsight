#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string s = "No";
    if (a == b) {
        if (a != c) {
            s = "Yes";
        }
    } else if (b == c) {
        if (b != a) {
            s = "Yes";
        }
    } else if (c == a) {
        if (c != b) {
            s = "Yes";
        }
    }
    cout << s << endl;
    return 0;
}