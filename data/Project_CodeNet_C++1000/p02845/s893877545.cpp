#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <cmath>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    ll n, a[100000], c[300002] = {3}, r = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        c[a[i] + 1]++;
        r = (r * c[a[i]]) % mod;
        c[a[i]]--;
    }
    cout << r << endl;
}