#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int h1, s1, h2, s2;
    cin >> h1 >> s1 >> h2 >> s2;

    while (true) {
        h2 -= s1;
        if (h2 <= 0) {
            cout << "Yes";
            return 0;
        }
        h1 -= s2;
        if (h1 <= 0) {
            cout << "No";
            return 0;
        }
    }

    return 0;
}