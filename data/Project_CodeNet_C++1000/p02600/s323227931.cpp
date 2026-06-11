#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x;
    cin >> x;
    if (400 <= x && x < 600)
        cout << 8 << endl;
    else if (x < 800)
        cout << 7 << endl;
    else if (x < 1000)
        cout << 6 << endl;
    else if (x < 1200)
        cout << 5 << endl;
    else if (x < 1400)
        cout << 4 << endl;
    else if (x < 1600)
        cout << 3 << endl;
    else if (x < 1800)
        cout << 2 << endl;
    else if (x < 2000)
        cout << 1 << endl;
    return 0;
}