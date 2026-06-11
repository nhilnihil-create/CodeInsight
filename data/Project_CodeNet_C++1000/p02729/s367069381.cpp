#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
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
const long long INF = 1LL << 60;
int cnt = 0;
int main()
{
    int n, m;
    cin >> n >> m;
    int n_ans, m_ans;
    n_ans = n >= 2 ? n * (n - 1) / 2 : 0;
    m_ans = m >= 2 ? m * (m - 1) / 2 : 0;
    cout << m_ans + n_ans << endl;

    return 0;
}
