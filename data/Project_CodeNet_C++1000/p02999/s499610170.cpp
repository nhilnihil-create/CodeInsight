#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, a;
    cin >> x >> a;
    if (x < a) {
        cout << '0';
    } else if (x >= a) {
        cout << "10";
    }
}