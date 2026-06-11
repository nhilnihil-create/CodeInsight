#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
