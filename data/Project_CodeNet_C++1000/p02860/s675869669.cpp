#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string res = "No";
    if (n % 2 == 0) {
        if (s.substr(0,n/2) == s.substr(n/2,n/2)) res = "Yes";
    }

    cout << res << endl;

    return 0;
}
