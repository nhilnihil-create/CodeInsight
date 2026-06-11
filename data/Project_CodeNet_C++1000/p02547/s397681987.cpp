#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i;
    int s[n];
    for(i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            s[i] = 1;
        }
        else {
            s[i] = 0;
        }
    }

    string ans = "No";
    for(i = 0; i < n-2; i++) {
        if (s[i] == 1 && s[i+1] == 1 && s[i+2] == 1) {
            ans = "Yes";
        }
    }

    cout << ans << endl;
}
