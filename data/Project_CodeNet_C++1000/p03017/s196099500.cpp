#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;

int main()
{
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    int cnt = 0;

    int wall = 0;
    for (int i = a-1; i < max(c, d); i++) {
        if (s[i] == '#') {
            cnt++;
        }
        else {
            if (wall < cnt) {
                wall = cnt;
            }
            cnt = 0;
        }
    }
    if (c < d) {
        if (wall < 2) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        return (0);
    }

    for (int i = b-1; i < d; i++) {
        if (s[i-1] == s[i] && s[i] == s[i+1] && s[i] == '.') {
            cout << "Yes" << endl;
            return (0);
        }
    }
    cout << "No" << endl;
}
