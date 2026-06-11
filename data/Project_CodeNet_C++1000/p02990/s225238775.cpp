#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 2005;
const int MOD = 1e9 + 7;
int fat[2 * MAX];

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

inline int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

int f_exp(int x, int e) {
    if (e == 0) return 1;
    if (e & 1) return mult(x, f_exp(x, e - 1));
    return f_exp(mult(x, x), e / 2);
}

inline int inv(int x) {
    return f_exp(x, MOD - 2);
}

inline int comb(int n, int k) {
    if (k > n) {
        return 0;
    }
    return mult(fat[n], mult(inv(fat[k]), inv(fat[n - k])));
}

int boxes_ways(int balls, int boxes) {
    int stars = balls;
    int separators = boxes - 1;
    return comb(stars + separators, stars);
}

void preprocess() {
    fat[0] = 1;
    fori (i, 1, 2 * MAX) {
        fat[i] = mult(fat[i - 1], i);
    }
}

void solve() {
    preprocess();
    int n, k;
    cin >> n >> k;
    int b = k;
    int r = n - k;
    if (r == 0) {
        cout << 1 << '\n';
        fori (i, 1, k) {
            cout << 0 << '\n';
        }
        return;
    }
    fori (i, 1, k + 1) {
        // BRBRB
        // BRBRBR
        if (r + 1 < i) {
            cout << 0 << '\n';
            continue;
        }
        int b_rest = b - i;
        int r_rest = r - (i - 1);
        int ans = mult(boxes_ways(b_rest, i), boxes_ways(r_rest, i - 1));
        if (r >= i) {
            r_rest = r - i;
            ans = add(ans, mult(2, mult(boxes_ways(b_rest, i), boxes_ways(r_rest, i))));
        }
        if (r >= i + 1) {
            r_rest = r - (i + 1);
            ans = add(ans, mult(boxes_ways(b_rest, i), boxes_ways(r_rest, i + 1)));
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

