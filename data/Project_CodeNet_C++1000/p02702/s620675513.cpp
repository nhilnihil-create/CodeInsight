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
    ll z = 0;
    int a = 0, b[2][2020] = {};
    cin >> s;
    for (int i = 1; i <= s.length(); i++) {
        a = (a * 10 + s[i - 1] - '0') % 2019;
        for (int j = 0; j < 2019; j++) b[i & 1][j] = 0;
        for (int j = 0; j < 2019; j++) b[i & 1][j * 10 % 2019] += b[~i & 1][j];
        z += b[i & 1][a];
        if (!a) z++;
        b[i & 1][a]++;
    }
    cout << z;
}
