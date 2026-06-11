#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int l[n];
    rep (i, n) cin >> l[i];
    int pos = 0;
    bool f = false;
    rep (i, n) {
        pos += l[i];
        if (pos > x) {
            cout << i + 1 << endl;
            f = true;
            break;
        }
    }
    if (!f) cout << n+1 << endl;
}

