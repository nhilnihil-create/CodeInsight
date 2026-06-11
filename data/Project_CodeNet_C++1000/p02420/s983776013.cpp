#include <iostream>
using namespace std;

int main()
{
    string s;
    int n, h;

    while (1) {
        cin >> s >> n;
        if (s == "-") break;
        while (n--) {
            cin >> h;
            string t;
            t += s.substr(h, s.length() - h);
            t += s.substr(0, h);
            s = t;
        }
        cout << s << endl;
    }

    return 0;
}