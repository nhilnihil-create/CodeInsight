#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;

    if (a == b) cout << 0 << endl;
    else {
        if ((a+b)%2 == 0) cout << (a+b)/2 << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
