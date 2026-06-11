#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n > 0) {
        int x = n % 10;
        if (x == 7) {
            cout << "Yes";
            return 0;
        }
        n = n / 10;
    }
    cout << "No";
}
