#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = n-3; i >= 0; i--) {
        if (s.substr(i, 3) == "ABC") ans++;
    }

    cout << ans << endl;
    return 0;
}
