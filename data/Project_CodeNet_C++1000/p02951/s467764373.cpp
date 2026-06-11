#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c;
    cin >> a >> b >> c;
    c = c - (a - b);

    if (c<0) cout << 0 << endl;
    else cout << c << endl;
    return 0;
}
