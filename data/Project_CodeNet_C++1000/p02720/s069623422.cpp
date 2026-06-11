#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int)3e5, MOD = (int)1e9 + 7, INF = (int)3e18;

int mn = INF;
map <int, int> mp;
vector <int> v;

void rec(int cur_num = 0) {
    if (cur_num > 3234566667) {
        return;
    }
    ++mp[cur_num];
    int ld = cur_num % 10;
    rec(cur_num * 10 + ld);
    if (ld + 1 <= 9) {
        rec(cur_num * 10 + ld + 1);
    } 
    if (ld - 1 >= 0) {
        rec(cur_num * 10 + ld - 1);
    }
}

main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k; 
    for (int i = 1; i <= 9; ++i) {
        rec(i);
    }
    int i = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ++i;
        if (i == k) {
            cout << it -> first;
            return 0;
        }
    }
    return 0;
}