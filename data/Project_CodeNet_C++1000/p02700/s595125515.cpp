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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (1)
    {
        c -= b;
        if (c <= 0)
        {
            cout << "Yes" << endl;
            break;
        }
        a -= d;
        if (a <= 0)
        {
            cout << "No" << endl;
            break;
        }
    }

    return 0;
}
