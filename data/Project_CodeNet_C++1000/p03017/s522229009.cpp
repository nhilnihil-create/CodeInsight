#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    bool ok = true;
    for (size_t i = (a-1); i < (c-1); i++)
    {
        if (s[i] == '#' && s[i+1] == '#') {
            ok = false;
        }
    }
    for (size_t i = (b-1); i < (d-1); i++)
    {
        if (s[i] == '#' && s[i+1] == '#') {
            ok = false;
        }
    }

    if (c > d) {
        bool snuke = false;
        for (size_t i = (b-2); i < (d-1); i++)
        {
            if (s.substr(i, 3) == "...") {
                snuke = true;
            }
        }
        cout << (snuke && ok ? "Yes" : "No") << endl;
    } else {
        cout << (ok ? "Yes" : "No") << endl;
    }
}