#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> a(205);
    a[0] = 300000;
    a[1] = 200000;
    a[2] = 100000;


    if (x == 1 && y == 1) {
        cout << a[x - 1] * 2 + 400000 << endl; 
    } else {
        cout << a[x - 1] + a[y - 1] << endl;
    }
    return 0;
}