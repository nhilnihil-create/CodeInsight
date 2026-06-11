#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, w;
    cin >> s >> w;
    if (s <= w) {
        cout << "unsafe";
    } else {
        cout << "safe";
    }
}
