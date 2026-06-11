#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define double long double
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef LOCAL
#define dbg(...) ;
#define endl '\n'
#endif

const int inf = 1e15;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int g[N];

signed main(){
    IOS;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        g[i] = a;
    }
    int slow = 1, fast = 1;
    do {
        slow = g[slow];
        fast = g[g[fast]];
    } while (slow != fast);
    int extra = 0;
    fast = 1;
    while (fast != slow) {
        fast = g[fast];
        slow = g[slow];
        extra++;
    }
    int len = 0;
    int start = slow;
    do {
        slow = g[slow];
        len++;
    } while (slow != fast);
    if (k <= extra) {
        start = 1;
        while (k--) {
            start = g[start];
        }
        cout << start << endl;
    }
    else {
        k -= extra;
        k %= len;
        while (k--) {
            start = g[start];
        }
        cout << start << endl;
    }
    return 0;
}