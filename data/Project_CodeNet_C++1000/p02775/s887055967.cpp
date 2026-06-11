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
    int d[1000006][2] = {};
    cin >> s;
    reverse(s.begin(), s.end());
    if (s[0] != '0') d[0][0] = s[0] - '0', d[0][1] = 10 - s[0] + '0';
    else d[0][0] = 0, d[0][1] = 10;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '9') {
            d[i][0] = d[i - 1][0] + 9;
            d[i][1] = min(d[i - 1][0] + 1, d[i - 1][1]);
        } else {
            d[i][0] = min(d[i - 1][0] + s[i] - '0', d[i - 1][1] + s[i] - '0' + 1);
            d[i][1] = min(d[i - 1][0] + 10 - s[i] + '0', d[i - 1][1] + 10 - s[i] + '0' - 1);
        }
        //cout << d[i][0] << ' ' << d[i][1] << '\n';
    }
    cout << min(d[s.length() - 1][0], d[s.length() - 1][1] + 1);
}
