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
    int n, c, z = 0;
    string s;
    cin >> n >> s;
    c = n - 1;
    while (c >= 0 && s[c] == 'W') c--;
    for (int i = 0; i < c; i++) if (s[i] == 'W') {
        swap(s[i], s[c]);
        z++;
        c--;
        while (c >= 0 && s[c] == 'W') c--;
    }
    cout << z;
}
