#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

const int LIM = 61;

vector<int> g(LIM, -1);

void add(int x) {
    for (int i = LIM - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (g[i] == -1) {
                g[i] = x;
                break;
            } else {
                x ^= g[i];
            }
        }
    } 
}

int solve(int x) {
    for (int i = LIM - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (g[i] == -1) {
                return 0;
            } else {
                x ^= g[i];
            }
        }
    } 
    return 1;
}

int can(int need, vector<int> care, vector<int> a) {
    int sm = 0;
    for (auto t : care) {
        sm |= (1LL << t);
    }
    fill(g.begin(), g.end(), -1);
    for (auto &t : a) {
        t &= sm;
        add(t);
    }
    return solve(need);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //x + x ^ s
    //s - hv does-not-mattter
    //s -nhv - better1
    int n;
    cin >> n;
    int s = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
        s ^= x;
        a.push_back(x);
    }
    int ans = 0;
    int alr = 0;
    vector<int> care;
    for (int i = LIM - 1; i >= 0; i--) {
        if ((s >> i) & 1) {
            ans += (1LL << i);
        } else {
            care.push_back(i);
            if (can(alr | (1LL << i), care, a)) {
                ans += 2 * (1LL << i);
                alr |= (1LL << i);
            } else {
                care.pop_back();
            }
        }
    }
    cout << ans << endl;
}