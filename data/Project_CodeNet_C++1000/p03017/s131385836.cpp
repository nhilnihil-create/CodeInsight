#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <chrono>

using namespace std;

const int MAXN = 200000;

char s[1 + MAXN];
bool dpa[1 + MAXN], dpb[1 + MAXN], dpc[1 + MAXN], dpd[1 + MAXN];

void dodp(int n, int x, bool* dp) {
    dp[x] = true;
    for (int i = x + 1; i <= n; i++)
        dp[i] = (s[i] != '#') && (dp[i - 1] || dp[i - 2]);
    for (int i = x - 1; i >= 1; i--)
        dp[i] = (s[i] != '#') && (dp[i + 1] || dp[i + 2]);
}

void print(bool answer) {
    if (answer)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    //ifstream cin("input.in");
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d >> (s + 1);
    dodp(n, a, dpa);
    dodp(n, b, dpb);
    dodp(n, c, dpc);
    dodp(n, d, dpd);
    if (c < d)
        print(dpa[c] && dpb[d]);
    else {
        for (int i = b; i <= d; i++)
            if (dpb[i] && dpd[i] && dpa[i - 1] && dpc[i + 1]) {
                print(true);
                return 0;
            }
        print(false);
    }
    return 0;
}





