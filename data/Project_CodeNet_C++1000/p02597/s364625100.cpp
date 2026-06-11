#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<char> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int ans = 0;
    int r = n;
    for (int l = 0; l < r; l++) {
        if (c[l] == 'W') {
            while (l != r) {
                r--;
                if (c[r] == 'R') {
                    ans++;
                    c[l] = 'R';
                    c[r] = 'W';
                    break;
                }
            }
            if (c[l] == 'W' && l != r) {
                ans++;
                c[l] = 'R';
            }
        }
    }

    cout << ans << endl;
    return 0;
}
