#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int b = 2;
    for (int i = 0; i < n; i++) {
        s[i] -= '1';
        if (s[i] == 1) b = 1;
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        r ^= (s[i] == b && (i & ~(n - 1)) == 0);
    }

    cout << r * b << endl;

    return 0;
}