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
    int n, l;
    cin >> n >> l;
    int mn = 300;
    int sum = 0;
    rep (i, n) {
        sum += l + i;
        if (abs(l + i) < abs(mn)) {
            mn = l + i;
        }
    }
    cout << sum - mn << endl;
}

