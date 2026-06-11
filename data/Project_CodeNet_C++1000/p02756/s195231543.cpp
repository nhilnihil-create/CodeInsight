#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s, r;
    char c;
    bool b = 0;
    int q, t, f;
    cin >> s >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            b = !b;
        } else {
            cin >> f >> c;
            if (!b) {
                if (f == 1) r += c;
                else s += c;
            } else {
                if (f == 1) s += c;
                else r += c;
            }
        }
    }
    if (!b) {
        reverse(r.begin(), r.end());
        cout << r + s;
    } else {
        reverse(s.begin(), s.end());
        cout << s + r;
    }
}
