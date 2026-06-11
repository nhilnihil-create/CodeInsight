#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vec cnt(N, 0);
    Rep (i, N) {
        ll A;
        cin >> A;
        A--;
        cnt[A]++;
    }

    map<ll, ll> m;
    for (auto e : cnt) {
        m[e]++;
    }

    vec kinds(3e5+20, 0);
    Rep (i, 3e5+10) {
        ll tmp = 0;
        for (auto e : m) {
            tmp += min(e.first, i) * e.second;
        }
        kinds[i] = tmp;
    }

    // Rep (i, 10) {
    //     cout << kinds[i] << " \n"[i==9];
    // }

    for (ll t = 1; t <= N; t++) {
        ll ok = 0, ng = 3e5+10;
        while (abs(ok-ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (kinds[mid] >= mid * t) ok = mid;
            else ng = mid;
        }
        cout << ok << "\n";
    }
}