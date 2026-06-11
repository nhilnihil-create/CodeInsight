
// Problem: B - Making Triangle
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_b
// Parsed on: 2020-09-02 13:00:08
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    int s;
    cin >> s;
    vector<int> arr(s);
    int ans = 0;
    for (auto &e : arr) cin >> e;
    for (int i = 0; i < s; i++)
        for (int j = i + 1; j < s; j++)
            for (int k = j + 1; k < s; k++) {
                if (arr[i] != arr[j] && arr[j] != arr[k] && arr[k] != arr[i]) {
                    vector<int> col = {arr[i], arr[j], arr[k]};
                    sort(col.begin(), col.end());
                    if (col[0] + col[1] > col[2]) ans++;
                }
            }

    cout << ans;
    return 0;
}
