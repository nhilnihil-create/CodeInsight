#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (b > a) b--;
        else if (b < a) {
            cout << "No" << endl;
            return 0;
        }
        a = b;
    }
    cout << "Yes" << endl;
}