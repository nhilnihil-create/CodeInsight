#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 3) == "ABC") {
            cnt++;
            i += 2;
        }
    }

    cout << cnt << endl;

    return 0;
}
