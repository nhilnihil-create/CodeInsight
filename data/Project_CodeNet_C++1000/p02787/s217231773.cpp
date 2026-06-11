#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e3 + 5;
const int MAXM = (int)1e4 + 5;


int n;
int A[MAXN], B[MAXN];
long long memo[MAXN][MAXM];

long long solve(int idx, int h) {
    if (h <= 0)
        return 0;
    if (idx == n)
        return INT_MAX;
    long long &ret = memo[idx][h];
    if (~ret)
        return ret;
    ret = solve(idx + 1, h);
    ret = min(ret, solve(idx + 1, h - A[idx]) + B[idx]);
    ret = min(ret, solve(idx, h - A[idx]) + B[idx]);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int h;
    cin >> h >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
    }

    memset(memo, -1, sizeof memo);
    cout << solve(0, h) << '\n';


    return 0;
}