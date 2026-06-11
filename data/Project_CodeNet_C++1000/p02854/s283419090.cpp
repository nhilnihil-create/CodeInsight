#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll sum = 0;
    rep(i,n) sum += a[i];
    int tmp = 0;
    vector<ll> left(n,0), right(n,0);
    left[0] = a[0];
    right[n-1] = a[n-1];
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] + a[i];
    }
    for (int i = n-1-1; i >= 0; i--) {
        right[i] = right[i+1] + a[i];
    }

    ll minx = INF;
    rep(i,n-1) {
        minx = min(minx, abs(left[i] - right[i+1]));
    }
    cout << minx << endl;

    return 0;
}
