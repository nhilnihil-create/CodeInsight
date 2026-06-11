#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n%2 != 0) {
        cout << "No" << endl;
        return 0;
    }

    bool ok = true;
    for (size_t i = 0; i < n/2; i++) {
        if (s[i] != s[i + n/2]) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
