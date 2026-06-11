#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    s = "0" + s;
    int n = s.size();
    vector<int> d = {0, INT_MAX};
    for (int i = n - 1; i >= 0; i--) {
        vector<int> dd = {INT_MAX, INT_MAX};
        int z = s[i] - '0';
        for (int j = 0; j < 2; j++) {
            if (d[j] == INT_MAX) continue;
            for (int x = 0; x < 10; x++) {
                // x - y - j (+10?) = z
                int y = (x - j - z + 10) % 10;
                int jj = (x - j - y) < 0;
                dd[jj] = min(dd[jj], d[j] + x + y);                
            }
        }
        d = dd;
    }
    cout << d[0];   

    return 0;
}