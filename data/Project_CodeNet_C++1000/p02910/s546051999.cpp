#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    bool ok = true;
    for (size_t i = 0; i < s.size(); i++) {
        if (((i+1)%2 != 0 && s[i] == 'L') || ((i+1)%2 == 0 && s[i] == 'R')) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
