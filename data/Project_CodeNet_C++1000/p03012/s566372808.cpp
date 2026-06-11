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

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for (int i=0; i<n; ++i) cin >> w[i], sum += w[i];
    int l = 0;
    int r = sum;
    int abs_mn = abs(r - l);
    for (int i=0; i<n; ++i) {
        l += w[i];
        r -= w[i];
        abs_mn = min(abs_mn, abs(r - l));
    }
    cout << abs_mn << endl;
}

