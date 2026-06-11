#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, o, z = 0;
    string s[6] = {};
    cin >> n >> m >> o;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < (1 << n); i++) for (int j = 0; j < (1 << m); j++) {
        int a = 0;
        for (int k = 0; k < n; k++) for (int l = 0; l < m; l++) if ((i & (1 << k)) && (j & (1 << l)) && s[k][l] == '#') a++;
        if (a == o) z++;
    }
    cout << z;
}
