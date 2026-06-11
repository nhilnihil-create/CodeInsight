#include <bits/stdc++.h>
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

int main()
{
    int a, b;
    cin >> a >> b;
    int let = 1, ans = 0;

    while (let < b)
    {
        --let;
        let += a;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
