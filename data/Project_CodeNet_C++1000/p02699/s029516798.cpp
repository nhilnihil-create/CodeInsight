#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int s, w;
    cin >> s >> w;
    if (w >= s) {
        cout << "unsafe";
    } else {
        cout << "safe";
    }

    return 0;
}