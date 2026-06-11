#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 3 , MOD = 998244353;
int a[N] , memo[N][N];
int n , s;

int mul (int a , int b) {
    return a * 1ll * b % MOD;
}

int add (int a , int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

int solve (int i , int rem) {
    if (i == n)
        return rem == 0;

    int &ret = memo[i][rem];
    if (~ret)
        return ret;

    ret = mul(2 , solve(i + 1 , rem));
    if (a[i] <= rem)
        ret = add(ret , solve(i + 1 , rem - a[i]));

    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    cin >> n >> s;
    for (int i = 0 ;i < n ;i++)
        cin >> a[i];

    memset(memo , -1 , sizeof memo);
    cout << solve(0 , s);
}
