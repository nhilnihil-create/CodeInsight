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
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t) {
        int n = (int)s.length();
        string a = s.substr(0, n / 2);
        string b = s.substr(n / 2 + 1, n / 2);
        string c = a, d = b;
        reverse(c.begin(), c.end());
        reverse(d.begin(), d.end());
        if (a == c && b == d) cout << "Yes";
        else cout << "No";
    } else cout << "No";
}
