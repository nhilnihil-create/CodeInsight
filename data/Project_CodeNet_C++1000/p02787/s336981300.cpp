#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3 , M = 1e4 + 4;
int memo[N][M];
int A[N] , B[N] , n;

int solve (int i , int rem) {
    if (rem <= 0)
        return 0;

    if (i == n)
        return 1e9;

    int &ret = memo[i][rem];
    if (~ret)
        return ret;

    return ret = min(solve(i + 1 , rem) , solve(i , rem - A[i]) + B[i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int h;
    cin >> h >> n;
    for (int i = 0 ;i < n ;i++)
        cin >> A[i] >> B[i];

    memset(memo , -1 , sizeof memo);
    cout << solve(0 , h);
}
