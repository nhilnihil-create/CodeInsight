#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;   cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << 0 << endl;
        return 0;
    }
    int *s = new int[m], *c = new int[m];
    for (int i = 0; i < m; i++)
        cin >> s[i] >> c[i];

    int *ans = new int[n];
    for (int i = 0; i < n; i++)
        ans[i] = -1;

    for (int i = 0; i < m; i++) {
        if (ans[s[i]-1] != -1 && ans[s[i]-1] != c[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans[s[i]-1] = c[i];
    }

    if (ans[0] == 0) {
        if (n == 1) {
            cout << 0 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }


    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            if (i == 0)
                cout << 1;
            else
                cout << 0;
        }
        else 
            cout << ans[i];
    }

    cout << endl;
    return 0;
}