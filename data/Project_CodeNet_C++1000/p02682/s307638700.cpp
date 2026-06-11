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



signed main(){
    IOS;
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if (a >= k) {
        ans = k;
    }
    else if (a + b >= k) {
        ans = a;
    }
    else if (a + b + c >= k) {
        ans = a - (k - a - b);
    }
    cout << ans << endl;
    return 0;
}