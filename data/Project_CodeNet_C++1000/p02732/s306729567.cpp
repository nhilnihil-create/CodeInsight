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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0);
    fori (i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll total = 0;
    fori (i, 1, n + 1) {
        total += (1LL * cnt[i] * (cnt[i] - 1)) / 2;
    }
    fori (i, 0, n) {
        ll cur = total - (cnt[a[i]] - 1);
        cout << cur << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

