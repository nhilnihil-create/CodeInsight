#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pb push_back
#define mp make_pair
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define endl "\n"

using namespace std;

const int N = 1500510;
const int inf = (int)(1e18) + 123;
const int mod = (1e9) + 7;
const double eps = 1e-9;

int n, sz;

multiset <int> S;

bool move(int x, multiset <int> &cur) {
    auto it = S.lower_bound(x);
    if (it == S.begin()) {
        return false;
    }
    it--;
    S.erase(it);
    cur.insert(*it);
    return true;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    sz = (1 << n);
    for(int i = 0; i < sz; ++i) {
        int x; cin >> x;
        S.insert(x);
    }
    multiset <int> a;
    move(inf, a);

    for(int i = 1; i <= n; ++i) {
        multiset <int> b;
        for(auto num : a) {
            if (!move(num, b)) {
                cout << "No";
                return 0;
            }
        }
        for(auto it : b) {
            a.insert(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}