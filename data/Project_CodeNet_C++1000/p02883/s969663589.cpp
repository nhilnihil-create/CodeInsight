#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<long long> a, f;
long long n, k;
long long z = 0;
bool check(long long x) {
    long long co = 0;
    for (int i = 0; i < n; i++) {
        long long m = x / f[i];
        co += max(z, a[i] - m);
    }
    if (co <= k) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        long long a1;
        cin >> a1;
        a.emplace_back(a1);
    }
    for (int i = 0; i < n; i++) {
        long long f1;
        cin >> f1;
        f.emplace_back(f1);
    }
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    long long ok = 1844674407300000000, ng = -1;
    while (ok - ng > 1) {
        long long mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
