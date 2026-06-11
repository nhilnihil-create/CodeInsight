#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

const int MAX = 100010;

int n, m;
ll dp[MAX];
bool broken[MAX];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        broken[a] = true;
    }
    dp[0] = 1;
    if (!broken[1])
    {
        dp[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
        if (broken[i])
        {
            dp[i] = 0;
        }
    }
    cout << dp[n] << endl;
    return 0;
}