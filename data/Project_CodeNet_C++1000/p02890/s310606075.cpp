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
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define ll long long
#define sz(x) (int)(x.size())
#define pb push_back
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"
#define int long long


const int N = (int)(1e6) + 322;
const long long inf = (long long)(1e18) + 123;
const int mod = (int)(1e9);
const double EPS = 1e-9;

map <int, int> cnt, cntofcnt;

vector <int> counts, fs;

int pref[N];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    for(auto it : cnt) {
        counts.pb(it.second);
    }
    counts.pb(0);
    sort(all(counts));
    for(int i = 1; i < sz(counts); ++i) {
        pref[i] = pref[i - 1] + counts[i];
    }

    for(int i = 1; i <= n; ++i) {
        int pos = lower_bound(all(counts), i) - counts.begin();
        int curans = (sz(counts) - pos);
        //cout << curans << ' ' << i << endl;
        curans += (pref[pos - 1] / i);
        fs.pb(curans);
    }
    reverse(all(fs));
    //for(auto i : fs) cout << i << ' ';
    //cout << endl;
    for(int i = 1; i <= n; ++i) {
        int pos = lower_bound(all(fs), i) - fs.begin();
        if (pos == n) {
            cout << 0 << endl;
        }else {
            cout << n - pos << endl;
        }
    }
    return 0;
}

