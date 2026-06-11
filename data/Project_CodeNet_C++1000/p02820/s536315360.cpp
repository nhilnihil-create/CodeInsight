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
    int n, k, r, s, p, z = 0;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    for (int i = 0; i < n; i++) {
        if (t[i] == 's') t[i] = 'r';
        else if (t[i] == 'r') t[i] = 'p';
        else t[i] = 's';
    }
    for (int i = 0; i < k; i++) {
        string u;
        for (int j = i; j < n; j += k) u += t[j];
        vector<int> d(u.length()), e(u.length());
        if (u[0] == 'r') e[0] = r;
        else if (u[0] == 's') e[0] = s;
        else e[0] = p;
        for (int j = 1; j < u.length(); j++) {
            d[j] = max(d[j - 1], e[j - 1]);
            if (u[j] == u[j - 1]) {
                if (u[j] == 'r') e[j] = d[j - 1] + r;
                else if (u[j] == 's') e[j] = d[j - 1] + s;
                else e[j] = d[j - 1] + p;
            } else {
                if (u[j] == 'r') e[j] = max(d[j - 1], e[j - 1]) + r;
                else if (u[j] == 's') e[j] = max(d[j - 1], e[j - 1]) + s;
                else e[j] = max(d[j - 1], e[j - 1]) + p;
            }
        }
        z += max(d[u.length() - 1], e[u.length() - 1]);
    }
    cout << z;
}
