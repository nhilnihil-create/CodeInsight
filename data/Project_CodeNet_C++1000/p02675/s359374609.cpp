#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n = n % 10;
    if (n == 2 || n == 4 || n == 5 || n == 7 || n == 7 || n == 9) {
        cout << "hon";
    } else if (n == 0 || n == 1 || n == 6 || n == 8) {
        cout << "pon";
    } else {
        cout << "bon";
    }
}
