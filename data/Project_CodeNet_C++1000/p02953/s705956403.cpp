#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a;
    cin >> a;
    a--;
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        if (b > a) b--;
        if (b < a) {
            cout << "No" << endl;
            return 0;
        }
        a = b;
    }
    cout << "Yes" << endl;
}
