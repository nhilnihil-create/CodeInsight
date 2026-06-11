#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7 , N = 1e5 + 5;
int memo[N][2];
string s;

int add(int a , int b) {
    a += b;
    while (a >= MOD) a -= MOD;
    return a;
}

int mul(int a , int b) {
    return a * 1ll * b % MOD;
}

int solve (int i , bool l) {
    if (i == s.size())
        return 1;

    int &ret = memo[i][l];
    if (~ret)
        return ret;

    ret = 0;
    int r = l ? 1 : s[i];
    for (int j = 0 ;j <= r ;j++)
        ret = add(ret , mul(solve(i + 1 , l | (j < s[i])) , j + 1));

    return ret;
}

int main() {
    cin >> s;
    for (char &c : s) c -= '0';
    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0);
}