#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7;
int p[N] , memo[N][14];
string s;

int mul(int a , int b , int m) {
    return a * 1ll * b % m;
}

int add(int a , int b , int m) {
    a += b;
    while (a >= m) a -= m;
    while (a < 0) a += m;
    return a;
}

int solve (int i , int m) {
    if (i == s.size())
        return m == 5;

    int &ret = memo[i][m];
    if (~ret)
        return ret;

    if (s[i] != '?')
        return ret = solve(i + 1 , add(m , mul(s[i] , p[s.size() - i - 1] , 13) , 13));

    ret = 0;

    for (int j = 0 ;j <= 9 ;j++)
        ret = add(ret , solve(i + 1 , add(m , mul(j , p[s.size() - i - 1] , 13) , 13)) , MOD);

    return ret;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    p[0] = 1;
    for (int i = 1 ;i < N ;i++)
        p[i] = p[i - 1] * 10 % 13;

    cin >> s;
    for (char &c : s) if (c != '?') c -= '0';
    memset(memo , -1 , sizeof memo);
    cout << solve(0 , 0);
}
