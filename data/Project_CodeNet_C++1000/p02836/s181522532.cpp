#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s.at(i) != s.at(n - 1 - i)) {
            ans++;
        }
    }
    cout << ans << endl;
}