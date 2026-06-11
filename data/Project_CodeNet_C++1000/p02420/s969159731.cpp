#include <iostream>
using namespace std;

int main(void) {
    string s;
    int m, h, c, n, i;
    while (1) {
        cin >> s;
        if (s == "-") break;
        cin >> m;
        n = s.size();
        c = 0;
        for (i = 0; i < m; i++) {
            cin >> h;
            c = (c + h) % n;
        }
        cout << s.substr(c) << s.substr(0, c) << endl;
    }
    return 0;
}