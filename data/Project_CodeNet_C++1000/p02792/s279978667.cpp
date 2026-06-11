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
    int n, a[10][10] = {};
    ll z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        a[s[0] - '0'][s.back() - '0']++;
    }
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) for (int l = 0; l < 10; l++) {
            if (j == k && i == l) {
                if (i == k && j == l) {
                    z += 1ll * a[i][j] * a[k][l];
                } else {
                    z += 1ll * a[i][j] * a[k][l];
                }
            }
        }
    }
    cout << z;
}
