#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
int n, m, v, p;
vector<int> A;
int judge(int now) {
    ll go = 0;
    REP(i, A.size()) {
        if (i < p-1) {
            go += m;
        }
        else if (i >= now) {
            go += m;
        }
        else {
            if (A[now] + m - A[i] < 0) return 0;
            go += A[now] + m - A[i];
        }
    }
    if (go < m*v) return 0;
    return 1;
}
void solve()  {
    cin >> n >> m >> v >> p;
    REP(i, n) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(ALL(A));
    reverse(ALL(A));
    int bot = p-1;
    int top = A.size();
    while (abs(top - bot) > 1) {
        int mid = (top + bot) / 2;
        if (judge(mid) == 1) {
            bot = mid;
        }
        else {
            top = mid;
        }
    }
    cout << bot+1 << endl;
}
#undef int
int main() {
    init();
    solve();
}