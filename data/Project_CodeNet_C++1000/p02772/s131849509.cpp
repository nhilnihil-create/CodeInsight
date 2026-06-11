#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string res = "APPROVED";
    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in % 2 == 0) {
            if (in % 3 != 0 && in % 5 != 0) res = "DENIED";
        }
    }

    cout << res << endl;

    return 0;
}
