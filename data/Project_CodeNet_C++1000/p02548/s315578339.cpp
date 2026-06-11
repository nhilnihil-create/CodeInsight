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
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    n--;
    ll res = 0;
    for(ll i = 1; i <= n; i++)  res += n/i;
    cout  << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;

    while(T--) {
        solve();
    }
    return 0;
}