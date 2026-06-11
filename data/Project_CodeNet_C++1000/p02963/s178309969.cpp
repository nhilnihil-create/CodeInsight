#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
int solve(int n) {
    int l = 0, r = 1000000001;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if(mid * mid > n)
            r = mid;
        else
            l = mid;
    }
    return l;
}
signed main(void) {
    int S;
    cin >> S;
    int x1, y1, x2, y2;
    x1 = solve(S);
    //cout << x1 << endl;
    if(S == x1 * x1) {
        y2 = x1;
        x2 = 0;
        y1 = 1;
    } else {
        if(S <= x1 * (x1 + 1)) {
            y2 = x1 + 1;
            x2 = x1 * y2 - S;
            y1 = 1;
        } else {
            x1++;
            y2 = x1;
            x2 = x1 * y2 - S;
            y1 = 1;
        }
    }
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << 0 << ' ' << 0 << endl;
}
