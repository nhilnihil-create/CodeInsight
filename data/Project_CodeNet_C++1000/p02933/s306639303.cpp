#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    string s;
    cin >> a >> s;
    if (a >= 3200) {
        cout << s;
    } else if (a < 3200) {
        cout << "red";
    }
}