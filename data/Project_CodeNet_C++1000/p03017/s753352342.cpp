//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


vector<int> ng;
bool can(int s, int g) {
    for (int x : ng) {
        if (s <= x && x <= g) return false;
    }
    return true;
}

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s;
    cin >> s;
    int cnt = 0;
    rep(i, n) {
        if (s[i] == '#') {
            cnt++;
            continue;
        }
        if (cnt >= 2) ng.push_back(i - cnt);
        cnt = 0;
    }
    if (cnt >= 2) ng.push_back(n - cnt);
    cnt = 0;
    int min_change = -1;
    for (int i = b-1; i < n; i++) {
        if (s[i] == '.') {
            cnt++;
            continue;
        }
        if (cnt >= 3) {
            min_change = i - cnt;
            cnt = 0;
            break;
        }
        cnt = 0;
    }
    if (cnt >= 3) min_change = min(min_change, n - cnt);

    if (!(can(a, c) && can(b, d))) {
        puts("No");
        return 0;
    }

    if (c < d) {
        puts("Yes");
        return 0;
    }

    if (min_change == -1 || min_change > d-1) {
        puts("No");
        return 0;
    }

    if (can(min_change + 2, c) && can(min_change + 1, d)) puts("Yes");
    else puts("No");

    return 0;
}