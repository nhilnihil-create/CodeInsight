#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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

ll n;
int main()
{
    int x;
    cin >> x;
    if (x < 600)
    {
        cout << 8 << endl;
    }
    else if (x < 800)
    {
        cout << 7 << endl;
    }
    else if (x < 1000)
    {
        cout << 6 << endl;
    }
    else if (x < 1200)
    {
        cout << 5 << endl;
    }
    else if (x < 1400)
    {
        cout << 4 << endl;
    }
    else if (x < 1600)
    {
        cout << 3 << endl;
    }
    else if (x < 1800)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}
