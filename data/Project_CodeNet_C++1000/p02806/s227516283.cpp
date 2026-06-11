#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
int main()
{
    int N;
    string X;
    cin >> N;
    vector<pair<int, string>> P(N);
    rep(i, N)
    {
        string s;
        int t;
        cin >> s;
        cin >> t;
        P[i].first = t;
        P[i].second = s;
    }
    cin >> X;
    int ans = 0;
    bool flag = false;
    rep(i, N)
    {
        if (flag)
        {
            ans += P[i].first;
        }
        if (P[i].second == X)
        {
            flag = true;
        }
        }
    cout << ans;
    return 0;
}