#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    vector<pair<int, int>> res;
    res.push_back({n + 1, 2});

    for (int i = 2; i + 1 <= n; i += 2) {
        res.push_back({i, i + 1});
        res.push_back({i + 1, 1});
        res.push_back({1, n + i});
        res.push_back({n + i, n + i + 1});
    }
    if (n % 2 == 0) {
        int x = 1;
        while (x * 2 <= n) x *= 2;
        int y = n - x;
        res.push_back({n, x + 1});
        res.push_back({n + n, y + n});
    }

    for (auto e : res) {
        cout << e.first << " " << e.second << "\n";
    }
//    for (auto e : res) {
//        cout << (e.first - 1) % n + 1 << " " << (e.second - 1) % n + 1 << "\n";
//    }

    return 0;
}