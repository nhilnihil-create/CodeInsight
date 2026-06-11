#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
    int x;
    cin >> x;

    int i = x / 100;
    if (x % 100 > 5 * i) {
        cout << 0 << endl;
    } else cout << 1 << endl;
}