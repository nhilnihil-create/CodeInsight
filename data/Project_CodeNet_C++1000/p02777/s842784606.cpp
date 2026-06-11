#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s, t, u;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    cin >> u;

    if (s == u) --a;
    else if (t == u) --b;

    cout << a << ' ' << b << endl;
    return 0;
}
