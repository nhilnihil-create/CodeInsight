#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int q; cin >> q;

    string subf, subb;
    bool state = false;

    auto rev = [&]() {
        state = !state;
    };
    auto front = [&](char c) {
        if (state) subb += c;
        else subf += c;
    };
    auto back = [&](char c) {
        if (state) subf += c;
        else subb += c;
    };

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            rev();
            continue;
        }
        int f; char c;
        cin >> f >> c;
        if (f == 1) front(c);
        else back(c);
    }

    reverse(subf.begin(), subf.end());
    s = subf + s + subb;
    if (state) {
        reverse(s.begin(), s.end());
    }
    cout << s << endl;
}

