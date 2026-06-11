#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, w;
    cin >> s >> w;

    string res = "unsafe";
    if (s > w) res = "safe";

    cout << res << endl;

    return 0;
}
