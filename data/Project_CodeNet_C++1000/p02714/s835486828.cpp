#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    long long r = 0, g = 0, b = 0;
    for (auto c : s) {
        r += c == 'R';
        g += c == 'G';
        b += c == 'B';
    }

    long long all = r * g * b;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // j - i = k - j
            // k = 2j - i
            int k = 2 * j - i;
            if (n <= k || s[i] == s[j] || s[i] == s[k] || s[j] == s[k]) continue;
            --all;
        }
    }

    cout << all << endl;
}

