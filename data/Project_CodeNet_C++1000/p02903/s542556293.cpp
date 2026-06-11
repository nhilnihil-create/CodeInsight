#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main () {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            cout << 0;
        }
        for (int j = a + 1; j <= w; j++) {
            cout << 1;
        }
        cout << endl;
    }
    for (int i = b + 1; i <= h; i++) {
        for (int j = 1; j <= a; j++) {
            cout << 1;
        }
        for (int j = a + 1; j <= w; j++) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}