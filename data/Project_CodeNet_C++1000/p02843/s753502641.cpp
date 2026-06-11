#include <bits/stdc++.h>
using namespace std;
int main() {
    int X; cin >> X;
    int C = X / 100;
    string ans = (100*C <= X && X <= 105*C) ? "1" : "0";
    cout << ans << endl;
    return 0;
}