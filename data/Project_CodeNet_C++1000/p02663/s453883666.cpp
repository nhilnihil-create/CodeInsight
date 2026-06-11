#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

int convert(int h, int m) {
    return h * 60 + m;
}

int main() {

    int h1, m1, h2, m2, need;
    cin >> h1 >> m1 >> h2 >> m2 >> need;

    int tm1 = convert(h1, m1);
    int tm2 = convert(h2, m2);

    cout << (tm2 - tm1 + 1) - need - 1 << endl;

    return 0;
}
